#include<bits/stdc++.h>

using namespace std;

int lg, All, N, K, T, maxT = 10000, aib[10009], cnt[10009];
pair < int, pair < int, int > > a[200009];

void U (int pos)
{
    int t = pos;
    while (pos <= maxT)
        cnt[pos] ++,
        aib[pos] += t,
        pos += pos - (pos & (pos - 1));
}

void Push (int t) {U (t), All ++;}

int getSum (int K)
{
    int pos = 0, ans = 0;
    for (int i=lg; i>=0; i--)
        if ((pos + (1 << i)) <= maxT && cnt[pos + (1 << i)] < K)
            pos |= 1 << i, K -= cnt[pos], ans += aib[pos];
    return ans + (pos + 1) * K;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &T);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second.first), a[i].second.second = i;
sort (a + 1, a + N + 1);
while ((1 << (lg + 1)) <= maxT) lg ++;
int pntr = N;
for (K=N; K>=1; K--)
{
    while (a[pntr].first >= K)
        Push (a[pntr--].second.first);
    if (All >= K)
    {
        int s = getSum (K);
        if (s <= T)
        {
            //printf ("%d < %d\n", s, T);
            break;
        }
    }
}
printf ("%d\n%d\n", K, K);
vector < pair < int, int > > v;
for (int i=pntr + 1; i<=N; i++)
    v.push_back ({a[i].second.first, a[i].second.second});
sort (v.begin (), v.end ());
for (int i=0; i<K; i++)
    printf ("%d ", v[i].second);
printf ("\n");
return 0;
}