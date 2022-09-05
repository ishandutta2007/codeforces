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

int N, M;
long long ans, add[400009], sum[400009];
set < pair < int , pair < int , int > > > segm;

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

void split (int nod, int l1, int l2)
{
    if (add[nod] == 0) return ;
    int f1 = nod << 1, f2 = (nod << 1) + 1;
    sum[f1] += 1LL * add[nod] * l1, sum[f2] += 1LL * add[nod] * l2;
    add[f1] += add[nod], add[f2] += add[nod];
    add[nod] = 0;
}

void U (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        add[nod] += val;
        sum[nod] += 1LL * val * (dr - st + 1);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod, mij - st + 1, dr - mij);
    if (x <= mij) U (nod<<1, st, mij, x, y, val);
    if (y > mij) U ((nod<<1) + 1, mij + 1, dr, x, y, val);
    sum[nod] = sum[nod<<1] + sum[(nod<<1) + 1];
}

void Q (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        ans += sum[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod, mij - st + 1, dr - mij);
    if (x <= mij) Q (nod<<1, st, mij, x, y);
    if (y > mij) Q ((nod<<1) + 1, mij + 1, dr, x, y);
}

void Update (int L, int R, int val)
{
    ///pair < right, pair < left, color > >
    set < pair < int , pair < int , int > > > :: iterator it = segm.lower_bound (make_pair (L, make_pair (0, 0))), it2;
    if (it->second.first < L)
    {
        int A = it->second.first, B = it->first, C = it->second.second;
        if (B > R)
        {
            U (1, 1, N, L, R, mod (val - C));
            segm.erase (it);
            segm.insert (make_pair (L - 1, make_pair (A, C)));
            segm.insert (make_pair (B, make_pair (R + 1, C)));
            segm.insert (make_pair (R, make_pair (L, val)));
            return ;
        }
        U (1, 1, N, L, B, mod (val - C));
        segm.erase (it);
        segm.insert (make_pair (L - 1, make_pair (A, C)));
        it = segm.lower_bound (make_pair (L, make_pair (0, 0)));
    }

    while (1)
    {
        if (it == segm.end ()) break;
        if (it->second.first > R) break;
        if (it->first > R)
        {
            int A = it->second.first, B = it->first, C = it->second.second;
            U (1, 1, N, A, R, mod (val - C));
            segm.erase (it);
            segm.insert (make_pair (B, make_pair (R + 1, C)));
            break;
        }
        it2 = it, it2 ++;
        U (1, 1, N, it->second.first, it->first, mod (val - it->second.second));
        segm.erase (it);
        it = it2;
    }

    segm.insert (make_pair (R, make_pair (L, val)));
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    segm.insert (make_pair (i, make_pair (i, i)));
while (M --)
{
    int tip, a, b, c;
    scanf ("%d", &tip);
    if (tip == 1)
    {
        scanf ("%d %d %d", &a, &b, &c);
        Update (a, b, c);
    }
    else
    {
        scanf ("%d %d", &a, &b), ans = 0LL;
        Q (1, 1, N, a, b);
        printf ("%I64d\n", ans);
    }
}
return 0;
}