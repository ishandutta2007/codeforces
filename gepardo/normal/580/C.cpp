/*
+--------------------( alex256 )--------------------+
|    Contest: 321 (Div. 2)                          |
|       Task: C                                     |
|       Date: 22.09.2015                            |
+---------------------------------------------------+
*/

#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define INF 2147483647
#define LLINF 9223372036854775807
#define PI 3.14159265358979323846
#define MAXN 1000000
#define LL long long
#define ULL unsigned long long
#define ar(a) a[MAXN]
#define pb push_back
#define ldout(v, prec) setprecision(prec) << v
#define debug(v) #v << " = \"" << v << "\""
#define ffor(i, n) for (int i = 0; i < n; i++)
#define bfor(i, n) for (int i = n - 1; i >= 0; i--)
#define xfor(i, f, t) for (int i = f; i <= t; i++)
#define xbfor(i, f, t) for (int i = t; i >= f; i--)
#define endless for (;;)

using namespace std;

bool will_it_be_AC()
{
    return true;
}

bool prime(LL n)
{
    for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

vector <LL> divs(LL n)
{
    vector <LL> v; LL i = 2;
    while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++;
    v.pb(n);
    return v;
}

LL gcd(LL a, LL b)
{
    return b ? gcd (b, a % b) : a;
}

LL extgcd(LL a, LL b, LL &x, LL &y)
{
	if (a == 0) { x = 0; y = 1; return b; }
	LL x1, y1, d = extgcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1; y = x1;
	return d;
}

template <typename T> void ivector(vector <T> &v, int size)
{
    ffor (i, size) cin >> v[i];
}

template <typename T> void ovector(vector <T> v, int size, string separator)
{
    if (size != 0) cout << v[0];
    xfor (i, 1, size - 1) cout << separator << v[i];
}

int init()
{
    ios_base::sync_with_stdio(0);
    return 0;
}

int get()
{
    int r; cin >> r; return r;
}

int q = init(), n = get(), m = get();
vector < vector<int> > graph(n);
vector <int> cats(n);
int ar(used) = {};
int res = 0;

void dfs(int v, int c)
{
    if (cats[v] == 1) c++; else c = 0;
    if (c > m) return;
    int go = 0;
    used[v] = true;
    ffor (i, graph[v].size())
    {
        int q = graph[v][i];
        if (used[q]) continue;
        go++;
        dfs(q, c);
    }
    if (go == 0) res++;
}

int main()
{
    ivector(cats, n);
    ffor (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(0, 0);
    cout << res;
    return 0;
}