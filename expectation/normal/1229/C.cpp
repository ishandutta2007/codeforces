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
 
int n,m;
LL num[200000 + 47];
vector<int> g[200000 + 47];

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    int n;
    cin >> n >> m;
    FOR (i,0,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b) swap(a,b);
        g[a].PB(b);
        num[a]++;
        num[b]++;
    }
    
    LL res = 0;
    FOR (i,0,n) res += g[i].size()*(num[i] - g[i].size());
    cout << res << "\n";
    
    int k;
    cin >> k;
    FOR (tmp,0,k)
    {
        int i;
        cin >> i;
        i--;
        res -= g[i].size()*(num[i] - g[i].size());
        FOR (j,0,g[i].size())
        {
            int to = g[i][j];
            res -= g[to].size()*(num[to] - g[to].size());
            g[to].PB(i);
            res += g[to].size()*(num[to] - g[to].size());
        }
        g[i].clear();
        cout << res << "\n";
    }
}