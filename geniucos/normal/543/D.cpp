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

int mod, N, a[200009], b[200009], suf[200009], t[200009];
vector < int > v[200009];

void dfs (int nod)
{
    a[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        dfs (*it);
        a[nod] = (1LL * a[nod] * (a[*it] + 1)) % mod;
    }
}

void dfb (int nod)
{
    suf[v[nod].size ()] = 1;
    for (int i=v[nod].size () - 1; i>=0; i --)
        suf[i] = (1LL * suf[i+1] * (a[v[nod][i]] + 1)) % mod;

    int curr = 1;
    for (int i=0; i<v[nod].size (); i++)
    {
        b[v[nod][i]] = (1LL * curr * suf[i+1]) % mod;
        b[v[nod][i]] = ((long long)1LL * b[v[nod][i]] * b[nod] + 1) % mod;
        curr = (1LL * curr * (a[v[nod][i]] + 1)) % mod;
    }

    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        dfb (*it);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]), v[t[i]].push_back (i);

mod = 1000000007;
dfs (1);
b[1] = 1;
dfb (1);

for (int i=1; i<=N; i++)
    printf ("%d ", (1LL * a[i] * b[i]) % mod);
printf ("\n");

return 0;
}