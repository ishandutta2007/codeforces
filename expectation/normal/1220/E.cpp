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
const int MOD = 10;
const LL LINF = MOD * (LL)MOD;

int n, m;
vector<int> g[300000], G[300000];
int step[300000];
bool root[300000];
int  par[300000];
LL   val[300000];
LL     A[300000];

void dfsS(int v)
{
    step[v] = 0;
    root[v] = 0;
    FOR (i,0,G[v].size())
        val[v] = max(val[v], val[G[v][i]] + A[G[v][i]]);
    
    FOR (i,0,g[v].size())
    {
        int to = g[v][i];
        if (step[to] != 0)
        {
            step[to]--;
            root[to] = 1;
            G[to].PB(v);
            par[v] = to;

            if (step[to] == 1)
            {
                dfsS(to);
            }

            return;
        }
    }
}

LL dfs(int v, int from)
{
    LL ans = 0;
    FOR (i,0,g[v].size())
    {
        int to = g[v][i];
        if (to != from)
            ans = max(ans, dfs(to, v));
    }
    
    return ans + A[v];
}

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    cin >> n >> m;
    FOR (i,0,n) cin >> A[i];
    FOR (i,0,m)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].PB(b);
        g[b].PB(a);
    }
    
    FOR (i,0,n) step[i] = (int)g[i].size();
    FOR (i,0,n)
    if (step[i] == 1)
        dfsS(i);
    
    FOR (v,0,n)
    if (root[v] == 1)
    {
        FOR (i,0,G[v].size())
            val[v] = max(val[v], val[G[v][i]] + A[G[v][i]]);
    }
    
    LL RES = 0;
    FOR (i,0,n)
    if (step[i] != 0)
        RES += A[i];
    
    int start;
    cin >> start; start--;
    if (step[start] != 0)
    {
        LL M = 0;
        FOR (i,0,n)
            M = max(M, val[i]);
        
        cout << RES + M;
        return 0;
    }
    
    bool tree = true;
    FOR (i,0,n)
    if (step[i] != 0)
        tree = false;
    
    if (tree)
    {
        cout << dfs(start, -1);
        return 0;
    }
    
    while (root[start] == 0)
    {
        RES += A[start];
        A[start] = 0;
        // cout << start << " "<<val[start]<<endl;
        start = par[start];
        val[start] = 0;
        FOR (i,0,G[start].size())
        {
            val[start] = max(val[start], val[G[start][i]] + A[G[start][i]]);
            // cout << "*"<<G[start][i]<<" "<<A[G[start][i]]<<endl;
        }
        // cout << start<<" "<<val[start]<<endl;
    }
    
    if (step[start] != 0)
    {
        LL M = 0;
        FOR (i,0,n)
        M = max(M, val[i]);
        
        cout << RES + M;
        return 0;
    }
}