#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define x first
#define y second

typedef long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 1000*1000*1000 + 7;
const LL LINF = MOD * (LL)MOD;

LL x[200000];
int n;
vector<pair<LL, LL>> stck[200000];
vector<int> g[200000];

LL res = 0;

LL gcd(LL a, LL b)
{
    if (!a || !b) return a+b;
    return gcd(b%a,a);
}

void dfs(int v, int p)
{
    vector<pair<LL, LL>> tmp;
    tmp.PB(MP(x[v], 1));
    if (p != -1)
    {
        FOR (i,0,stck[p].size())
        {
            LL val = gcd(stck[p][i].first, x[v]);
            tmp.PB(MP(val,stck[p][i].second));
        }
    }
    
    sort(tmp.begin(), tmp.end());
    FOR (i,0,tmp.size())
    if (stck[v].size() == 0 || stck[v].back().first != tmp[i].first)
        stck[v].PB(tmp[i]);
    else
        stck[v].back().second = (stck[v].back().second + tmp[i].second)%MOD;
    
    FOR (i,0,stck[v].size())
        res = (res + stck[v][i].first % MOD * stck[v][i].second)%MOD;
    
    FOR (i,0,g[v].size())
    if (g[v][i] != p)
        dfs(g[v][i], v);
}

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    int n;
    cin >> n;
    FOR (i,0,n) cin >> x[i];
    FOR (i,1,n)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].PB(b);
        g[b].PB(a);
    }
    
    dfs(0, -1);
    cout << res;
}