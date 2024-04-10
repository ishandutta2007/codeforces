#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int ansAint, maxl, knt, dis, nr, N, M, sti[400009], a[400009], pref[400009], suf[400009], ans[400009], aib[800009], maaib[800009], ma[3200009], bef[400009], aft[400009], SF[400009], V1[400009], V2[400009], unic[400009];
pair < int , int > norm[800009];
pair < int , pair < int , int > > b[400009];

void Normalize ()
{
    sort (norm + 1, norm + nr + 1);
    for (int i=1; i<=nr; i++)
    {
        if (i == 1 || norm[i].first != norm[i - 1].first) dis ++;
        if (norm[i].second > 0) a[norm[i].second] = dis;
        else b[-norm[i].second].second.first = dis;
    }
}

void Update (int pos, int val)
{
    while (pos <= dis)
    {
        if (val > aib[pos]) aib[pos] = val;
        pos += pos - (pos & (pos - 1));
    }
}

int Query (int pos)
{
    int bst = 0;
    while (pos)
    {
        if (aib[pos] > bst) bst = aib[pos];
        pos &= pos - 1;
    }
    return bst;
}

void BuildPrefSuf ()
{
    for (int i=1; i<=N; i++)
        sti[i] = dis + 1;
    int j = 1;
    for (int i=1; i<=N; i++)
    {
        while (b[j].first == i) V1[j] = Query (b[j].second.first - 1), j ++;
        pref[i] = Query (a[i] - 1) + 1;
        Update (a[i], pref[i]);
        if (pref[i] > maxl)
            maxl = pref[i];
    }
    for (int i=1; i<=dis; i++)
        aib[i] = 0;
    for (int i=1; i<=N; i++)
        sti[i] = 0;
    sti[0] = dis + 1;
    j = M;
    for (int i=N; i>=1; i--)
    {
        while (b[j].first == i) V2[j] = Query (dis - b[j].second.first), j --;
        suf[i] = Query (dis - a[i]) + 1;
        Update (dis - a[i] + 1, suf[i]);
    }
    for (int i=1; i<=N; i++)
        unic[pref[i]] += (pref[i] + suf[i] - 1 == maxl);
}

void UpAib (int pos, int val)
{
    while (pos <= dis)
    {
        if (val > maaib[pos])
            maaib[pos] = val;
        pos += pos - (pos & (pos - 1));
    }
}

int QAib (int pos)
{
    int val = 0;
    while (pos)
    {
        if (maaib[pos] > val)
            val = maaib[pos];
        pos &= pos - 1;
    }
    return val;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), norm[++nr] = make_pair (a[i], i);
for (int i=1; i<=M; i++)
    scanf ("%d %d", &b[i].first, &b[i].second.first), b[i].second.second = i, norm[++nr] = make_pair (b[i].second.first, -i);
Normalize ();
sort (b + 1, b + M + 1);
BuildPrefSuf ();
int j = M;
for (int i=N; i>=1; i--)
{
    while (b[j].first == i)
        SF[j] = QAib (dis - b[j].second.first), j --;
    UpAib (dis - a[i] + 1, suf[i]);
}
for (int i=1; i<=dis; i++)
    maaib[i] = 0;
j = 1;
for (int i=1; i<=N; i++)
{
    while (b[j].first == i)
    {
        int bf = QAib (b[j].second.first - 1), sf = SF[j];
        if (bf + sf == maxl) ans[b[j].second.second] = maxl + 1;
        else
        if (pref[i] + suf[i] - 1 == maxl && unic[pref[i]] == 1)
        {
            ///era necesar
            if (bef[i] >= b[j].second.first || aft[i] <= b[j].second.first)
            {
                ///inca mai sunt 2 cazuri de maxl... (in mod normal intervalul e determinat dar se poate sa fie o parte vida)
                if (V1[j] + V2[j] + 1 == maxl) ans[b[j].second.second] = maxl;
                else ans[b[j].second.second] = maxl - 1;
            }
            else ans[b[j].second.second] = maxl;
        }
        else ans[b[j].second.second] = maxl;
        j ++;
    }
    UpAib (a[i], pref[i]);
}
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}