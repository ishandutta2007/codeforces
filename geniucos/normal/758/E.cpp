#include<bits/stdc++.h>

using namespace std;

int N, P[200009], W[200009], leftEnd[200009], rightEnd[200009];
long long allW[200009], minW[200009], maxW[200009], ans[200009];
vector < pair < int, int > > v[200009];

void dfs (int nod, int tata, int i)
{
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
        {
            int x = it->first, i = it->second;
            dfs (x, nod, i);
            allW[nod] += allW[x] + W[i];
            maxW[nod] += maxW[x] + W[i];
            minW[nod] += minW[x] + W[i] - min ((long long) W[i] - 1, P[i] - minW[x]);
        }
    if (nod != 1)
    {
        maxW[nod] = min (maxW[nod], (long long) P[i]);
        if (minW[nod] > P[i])
        {
            printf ("-1\n");
            exit (0);
        }
    }
}

long long solve (int nod, int tata, long long giveUp)
{
//    printf ("%d %I64d\n", nod, giveUp);
    long long totalW = 0;
        for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
            giveUp -= (allW[it->first] - maxW[it->first]);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
        {
            long long s = min (maxW[it->first] - minW[it->first], giveUp);
            long long subW = solve (it->first, nod, s + allW[it->first] - maxW[it->first]); giveUp -= s;
            long long ma = min (P[it->second] - subW, (long long) W[it->second] - 1);
            s = min (ma, giveUp), giveUp -= s, ans[it->second] = s;
            totalW += W[it->second] - s + subW;
        }
    return totalW;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d %d %d", &x, &y, &W[i], &P[i]), leftEnd[i] = x, rightEnd[i] = y;
    v[x].push_back ({y, i});
    v[y].push_back ({x, i});
}
dfs (1, -1, 0);
solve (1, -1, allW[1] - maxW[1]);
printf ("%d\n", N);
for (int i=1; i<N; i++)
    printf ("%d %d %I64d %I64d\n", leftEnd[i], rightEnd[i], (long long) W[i] - ans[i], (long long) P[i] - ans[i]);
return 0;
}