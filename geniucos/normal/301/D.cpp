#include<bits/stdc++.h>

using namespace std;

int N, M, pos[200009], ans[200009], aib[200009];
pair < int, pair < int, int > > q[200009];
vector < int > v[200009], h[200009];

void Up (int pos, int val) {while (pos <= N) aib[pos] += val, pos += pos - (pos & (pos - 1));}
int Qry (int pos) {int sum = 0; while (pos) sum += aib[pos], pos &= pos - 1; return sum;}
void Clear () {for (int i=0; i<=N; i++) aib[i] = 0;}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x), pos[x] = i;
}
for (int i=1; i<=M; i++)
    scanf ("%d %d", &q[i].first, &q[i].second.first), q[i].second.second = i;
sort (q + 1, q + M + 1);
for (int i=1; i<=N; i++)
    for (int j=i; j<=N; j+=i)
    {
        int x = min (pos[i], pos[j]), y = max(pos[i], pos[j]);
        v[x].push_back (y);
    }
int j=N;
for (int i=M; i>=1; i--)
{
    while (j>=q[i].first)
    {
        for (auto it = v[j].begin (); it != v[j].end (); it ++)
            Up (*it, +1);
        j --;
    }
    ans[q[i].second.second] += Qry (q[i].second.first);
}
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}