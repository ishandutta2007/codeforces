#include<bits/stdc++.h>

using namespace std;

int N, C, D, ans, maxC, maxD, val[200009], b[200009], ma[200009];
char type[200009];
vector < pair < int, int > > v, h;

int solve (vector < pair < int, int > > v, int lim)
{
    if (v.size () == 1) return -1;
    int nr = v.size ();
    sort (v.begin (), v.end ());
    for (int i=0; i<nr; i++)
        val[i + 1] = v[i].second, b[i + 1] = v[i].first;
    for (int i=1; i<=nr; i++)
        ma[i] = max (ma[i - 1], val[i]);
    int j = nr, ans = -1;
    for (int i=1; i<=nr; i++)
    {
        while (j > 0 && b[j] + b[i] > lim) j --;
        if (j > 0 && i > 1)
        {
            int k = min (j, i - 1);
            int curr = ma[k] + val[i];
            if (curr > ans) ans = curr;
        }
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &C, &D), maxC = maxD = -1, ans = -1;
for (int i=1; i<=N; i++)
{
    scanf ("%d %d %c", &val[i], &b[i], &type[i]);
    if (type[i] == 'C' && b[i] <= C)
    {
        if (val[i] > maxC) maxC = val[i];
        v.push_back ({b[i], val[i]});
    }
    else
    if (type[i] == 'D' && b[i] <= D)
    {
        if (val[i] > maxD) maxD = val[i];
        h.push_back ({b[i], val[i]});
    }
}
if (maxC != -1 && maxD != -1) ans = maxC + maxD;
int v1 = solve (v, C), v2 = solve (h, D);
if (v1 > ans) ans = v1;
if (v2 > ans) ans = v2;
if (ans == -1) printf ("0\n");
else printf ("%d\n", ans);
return 0;
}