#include<bits/stdc++.h>

using namespace std;

int N, a[100009];
long long INF = 1e15 + 100;
pair < int, int > tar1, tar2;

int minMul (int a, int b)
{
    ///a * x >= b min x
    if (a >= b) return 1;
    if (b % a == 0) return b / a;
    return b / a + 1;
}

vector < long long > getM (vector < int > v)
{
    vector < long long > ans;
    for (int msk = 0; msk < (1 << v.size ()); msk ++)
    {
        long long curr = 1;
        for (int i=0; i<v.size (); i++)
            if (msk & (1 << i))
                curr = 1LL * curr * v[i];
        ans.push_back (curr);
    }
    return ans;
}

bool ok2 (int pref, pair < int, int > tar)
{
    long long prod = 1;
    for (int i=1; i<=pref; i++)
    {
        if (INF / a[i] <= prod) return 1;
        prod = 1LL * prod * a[i];
    }
    vector < int > g, h;
    for (int i=1; i<=pref; i++)
        if (i <= pref / 2) g.push_back (a[i]);
        else h.push_back (a[i]);
    vector < long long > half1 = getM (g), half2 = getM (h);
    sort (half1.begin (), half1.end ());
    sort (half2.begin (), half2.end ());
    long long st = tar.first, dr = prod / tar.second;
    if (dr < st) return 0;
    for (auto it = half1.begin (); it != half1.end (); it ++)
    {
        auto it2 = upper_bound (half2.begin (), half2.end (), dr / (*it));
        if (it2 != half2.begin ())
        {
            it2 --;
            if (1LL * (*it2) * (*it) >= st) return 1;
        }
    }
    return 0;
}

bool ok (int pref)
{
    if (ok2 (pref, tar1)) return 1;
    if (ok2 (pref, tar2)) return 1;
    return 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int A, B, W, H;
scanf ("%d %d %d %d %d", &A, &B, &W, &H, &N);
tar1 = {minMul (W, A), minMul (H, B)};
tar2 = {minMul (W, B), minMul (H, A)};
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1), reverse (a + 1, a + N + 1);
int p = 0, u = min (N, 34), mij, ras = -1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);
return 0;
}