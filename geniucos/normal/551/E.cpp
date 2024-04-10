#include<cstdio>
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

int nr, sq, N, M, unde[500009], left[3000], right[3000], l[3000];
long long cat[500009], a[500009];
pair < long long , int > v[209][2509];

void refresh (int bucata)
{
    l[bucata] = 0;
    for (int i=left[bucata]; i<=right[bucata]; i++)
        v[bucata][++l[bucata]].first = a[i], v[bucata][l[bucata]].second = i;
    sort (v[bucata] + 1, v[bucata] + l[bucata] + 1);
}

int prima (int bucata, int val)
{
    int p, u, ras = -1;
    p = 1;
    u = l[bucata];
    while (p <= u)
    {
        int mij = (p + u) >> 1;
        if (v[bucata][mij].first >= val)
            ras = mij, u = mij - 1;
        else
            p = mij + 1;
    }
    if (ras != -1 && v[bucata][ras].first == val)
        return v[bucata][ras].second;
    return -1;
}

int ultimul (int bucata, int val)
{
    int p, u, ras = -1;
    p = 1;
    u = l[bucata];
    while (p <= u)
    {
        int mij = (p + u) >> 1;
        if (v[bucata][mij].first <= val)
            ras = mij, p = mij + 1;
        else
            u = mij - 1;
    }
    if (ras != -1 && v[bucata][ras].first == val)
        return v[bucata][ras].second;
    return -1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]);
sq = 2500;
for (int i=1; i<=N; i += sq)
{
    nr ++;
    left[nr] = i;
    for (int j=i; j <= i+sq-1 && j <= N; j++)
        unde[j] = nr, right[nr] = j;
    refresh (nr);
}
while (M)
{
    int tip;
    M --;
    scanf ("%d", &tip);
    if (tip == 1)
    {
        int st, dr, x;
        scanf ("%d %d %d", &st, &dr, &x);
        if (unde[dr] - unde[st] <= 1)
        {
            for (int i=st; i<=dr; i++)
                a[i] += x;
            refresh (unde[st]);
            if (unde[dr] != unde[st])
                refresh (unde[dr]);
            continue;
        }
        for (int i=st; i<=right[unde[st]]; i++)
            a[i] += x;
        refresh (unde[st]);
        for (int i=left[unde[dr]]; i<=dr; i++)
            a[i] += x;
        refresh (unde[dr]);
        for (int i=unde[st] + 1; i < unde[dr]; i ++)
            cat[i] += x;
    }
    else
    {
        int fir, lst, y;
        scanf ("%d", &y);
        fir = lst = -1;
        for (int i=1; i<=nr; i++)
        {
            if (cat[i] > y)
                continue;
            int aux1;
            aux1 = prima (i, y - cat[i]);
            if (aux1 == -1)
                continue;
            fir = aux1;
            break;
        }
        for (int i=nr; i>=1; i--)
        {
            if (cat[i] > y)
                continue;
            int aux1;
            aux1 = ultimul (i, y - cat[i]);
            if (aux1 == -1)
                continue;
            lst = aux1;
            break;
        }
        if (fir == -1)
            printf ("-1\n");
        else
            printf ("%d\n", lst - fir);
    }
}
return 0;
}