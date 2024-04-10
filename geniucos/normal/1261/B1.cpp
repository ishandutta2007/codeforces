#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int lg, N, M, init[maxN], ans[maxN], aib[maxN];
pair<int, int> a[maxN];
vector<pair<int, int>> qr[maxN];

void mark(int pos)
{
    while(pos <= N)
        aib[pos] ++,
        pos += pos - (pos & (pos - 1));
}

int getKth(int k)
{
    k --;
    int pos = 0;
    for (int i=lg; i>=0; i--)
        if (pos + (1 << i) <= N && aib[pos | (1 << i)] <= k)
            pos |= 1 << i, k -= aib[pos];
    return pos + 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &init[i]), a[i].first = -init[i], a[i].second = i;
while ((2 << lg) <= N)
    lg ++;
sort(a + 1, a + N + 1);
scanf ("%d", &M);
for (int i=1; i<=M; i++)
{
    int k, pos;
    scanf ("%d %d", &k, &pos);
    qr[k].push_back({pos, i});
}
for (int i=1; i<=N; i++)
{
    mark(a[i].second);
    for (auto q : qr[i])
        ans[q.second] = init[getKth(q.first)];
}
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/