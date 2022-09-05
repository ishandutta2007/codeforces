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

int curr, mod, nr, sqr, M, N, scot[1000009], bag[1000009], ans[200009], st[200009], dr[200009], pr[10009], ap[1000009], P[200009], a[200009];
int h[9][200009];
bool cr[1000009];
vector < pair < int , int > > v[1009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

bool cmp (int i, int j)
{
    return (st[i] / sqr < st[j] / sqr);
}

int inv (int val)
{
    int aux = pow (val, mod - 2);
    return aux;
}

void Push (int i)
{
    for (int k=1; k<=h[0][i]; k++)
    {
        if (ap[h[k][i]] == 0) curr = (1LL * curr * bag[h[k][i]]) % mod;
        ap[h[k][i]] ++;
    }
}

void Pop (int i)
{
    for (int k=1; k<=h[0][i]; k++)
    {
        ap[h[k][i]] --;
        if (ap[h[k][i]] == 0) curr = (1LL * curr * scot[h[k][i]]) % mod;
    }
}

void Read (int &x);

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
mod = 1e9 + 7;
for (int i=2; i <= 1000; i++)
    if (cr[i] == 0)
    {
        for (int j=i * i; j<=1000000; j+=i)
            cr[j] = 1;
    }
for (int i=2; i<=1000; i++)
    if (cr[i] == 0) pr[++nr] = i;

for (int i=2; i<=1000000; i++)
    if (cr[i] == 0)
    {
        bag[i] = (1LL * (i - 1) * inv (i)) % mod;
        scot[i] = (1LL * i * inv (i - 1)) % mod;
    }

Read (N), P[0] = 1;
for (int i=1; i<=N; i++)
{
    Read (a[i]);
    P[i] = (1LL * P[i-1] * a[i]) % mod;
    int aux = a[i];
    for (int j=1; pr[j] * pr[j] <= aux && j <= nr; j++)
        if (aux % pr[j] == 0)
        {
            while (aux % pr[j] == 0) aux /= pr[j];
            h[++h[0][i]][i] = pr[j];
        }
    if (aux > 1) h[++h[0][i]][i] = aux;
}
Read (M), sqr = 500;
for (int i=1; i<=M; i++)
{
    Read (st[i]), Read (dr[i]);
    ans[i] = (1LL * P[dr[i]] * inv (P[st[i] - 1])) % mod;
    if (dr[i] - st[i] <= sqr)
    {
        for (int j=st[i]; j<=dr[i]; j++)
            for (int k=1; k<=h[0][j]; k++)
                if (ap[h[k][j]] == 0)
                {
                    ans[i] = (1LL * ans[i] * bag[h[k][j]]) % mod;
                    ap[h[k][j]] = 1;
                }
        for (int j=st[i]; j<=dr[i]; j++)
            for (int k=1; k<=h[0][j]; k++)
                ap[h[k][j]] = 0;
        continue;
    }
    v[st[i] / sqr].push_back (make_pair (dr[i], i));
}

for (int i=0; (i + 1) * sqr <= N; i++)
    if (!v[i].empty ())
    {
        sort (v[i].begin (), v[i].end ());
        ///toate au dr mai incolo
        int Dr = sqr * (i + 1), curr_j = Dr;
        curr = 1;
        for (vector < pair < int , int > > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
        {
            while (curr_j <= it->first)
                Push (curr_j), curr_j ++;
            for (int j=Dr-1; j>=st[it->second]; j--)
                Push (j);
            ans[it->second] = (1LL * ans[it->second] * curr) % mod;
            for (int j=Dr-1; j>=st[it->second]; j--)
                Pop (j);
        }
        for (int j=curr_j - 1; j>=Dr; j--)
            Pop (j);
    }

for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}

#define maxl 100000
char sir[maxl];
int pos = 0;

void Next ()
{
    if (++pos == maxl)
        fread (sir, 1, maxl, stdin), pos = 0;
}

void Read (int &x)
{
    for (;sir[pos] < '0' || sir[pos] > '9'; Next ());
    for (x = 0; sir[pos] >= '0' && sir[pos] <= '9'; Next ()) x = x * 10 + sir[pos] - '0';
}