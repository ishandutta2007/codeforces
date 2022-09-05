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

int a, ta, b, tb, x[100], y[100], px, py, f[5];
long long F, ans, mod, tab, tmod, perioada;
struct mat
{
    long long v[2][2];
}baza, curr_ans;

void init_fibo ()
{
    baza.v[0][0] = 0LL;
    baza.v[0][1] = baza.v[1][0] = baza.v[1][1] = 1LL;
}

long long prd (long long a, long long b)
{
    long long ans = 0;
    for (int i=0; (1LL << i) <= b; i++)
    {
        if (b & (1LL << i))
        {
            ans += a;
            if (ans >= mod)
                ans -= mod;
        }
        a += a;
        if (a >= mod)
            a -= mod;
    }
    return ans;
}

mat prod (mat a, mat b)
{
    mat c;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
        {
            c.v[i][j] = 0;
            for (int k=0; k<2; k++)
                c.v[i][j] = ((long long) c.v[i][j] + prd (a.v[i][k], b.v[k][j])) % mod;
        }
    return c;
}

mat pow_mat (mat a, long long b)
{
    mat ans;
    ans.v[0][0] = ans.v[1][1] = 1LL;
    ans.v[0][1] = ans.v[1][0] = 0LL;
    for (int i=0; (1LL << i) <= b; i++)
    {
        if (b & (1LL << i))
            ans = prod (ans, a);
        a = prod (a, a);
    }
    return ans;
}

long long get_Nth (long long N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    curr_ans = pow_mat (baza, N - 1);
    return curr_ans.v[1][1];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//mod = 1220703125LL; -> 4882812500
//mod = 8192;
//1.5 * 5^13 * 2^13 /
/*for (mod = 125; mod <= 125; mod = mod * 5)
{
    f[0] = 0, f[1] = 1, mp[make_pair (0, 1)] = 1;
    for (int i=2; i<=100000000; i++)
    {
        f[i % 3] = (f[(i-1) % 3] + f[(i-2) % 3]) % mod;
        if (mp[make_pair (f[(i-1) % 3], f[i % 3])])
        {
            printf ("%I64d->%d\n", mod, i - mp[make_pair (f[(i-1) % 3], f[i % 3])]);
            break;
            //return 0;
        }
        mp[make_pair (f[(i-1) % 3], f[i % 3])] = i;
    }
    mp.clear ();
}*/

/*mod = 10000000000000LL;
a = 8192, ta = 12288;
b = 1953125, tb = 7812500;
tmod = 15000000000000LL;
tab = 24000000000LL;
init_fibo ();

f[0] = 0, f[1] = 1;
for (int i=0; i<ta; i++)
{
    if (i >= 2)
        f[i % 3] = (f[(i-1) % 3] + f[(i-2) % 3]) % a;
    if (F % a == f[i % 3])
        x[++px] = i;
}

f[0] = 0, f[1] = 1;
for (int i=0; i<tb; i++)
{
    if (i >= 2)
        f[i % 3] = (f[(i-1) % 3] + f[(i-2) % 3]) % b;
    if (F % b == f[i % 3])
        y[++py] = i;
}

ans = -1;
for (int I=1; I<=px; I++)
    for (int J=1; J<=py; J++)
    {
        int i = x[I], j = y[J];
        long long P = -1;
        for (int p=0; p<ta; p++)
            if (((long long)1LL * p * tb + j - i) % ta == 0 && (long long)1LL * p * tb + j >= i)
            {
                P = (long long)1LL * p * tb + j;
                break;
            }
        if (P == -1)
            continue;
        while (1)
        {
            if (get_Nth (P) == F)
            {
                if (ans == -1 || P < ans)
                    ans = P;
                break;
            }
            P += tab;
            if (P >= tmod)
                break;
        }
    }
printf ("%I64d\n", ans);*/
scanf ("%I64d", &F);
init_fibo ();
mod = 1LL;
perioada = 1LL;
vector < long long > poate;
poate.push_back (0);
for (int i=1; i<=13; i++)
{
    mod = mod * 10LL;
    long long Old = perioada;
    mat pas = pow_mat (baza, Old);
    perioada = perioada * 10;
    if (i == 1)
        perioada = 60LL;
    vector < long long > curr;
    for (vector < long long > :: iterator it = poate.begin (); it != poate.end (); it ++)
    {
        long long P = *it;
        bool first = 1;
        while (P < perioada)
        {
            if (P < 2 || first == 1)
            {
                if (P >= 2) first = 0;
                if (get_Nth (P) == F % mod)
                    curr.push_back (P);
            }
            else
            if (curr_ans.v[1][1] == F % mod)
                curr.push_back (P);
            P += Old;
            if (first == 0) curr_ans = prod (curr_ans, pas);
        }
    }
    sort (curr.begin (), curr.end ());
    curr.erase (unique (curr.begin (), curr.end ()), curr.end ());
    poate = curr;
/*    for (vector < long long > :: iterator it = curr.begin (); it != curr.end (); it ++)
        printf ("%I64d ", *it);
    printf ("\n");*/
//    printf ("%d\n", curr.size ());
}
if (poate.empty ()) printf ("-1\n");
else printf ("%I64d\n", poate[0]);
return 0;
}