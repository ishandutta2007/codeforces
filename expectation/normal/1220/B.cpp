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


string s;
int n;
LL a[2000][2000];
LL ans[2000];

bool check(int a0)
{
    ans[0] = a0;
    FOR (i,1,n)
    {
        if (a[0][i]%a0 != 0)
            return false;
        ans[i] = a[0][i]/a0;
    }
    
    FOR (i,1,n)
    FOR (j,i+1,n)
    if (ans[i]*ans[j] != a[i][j])
        return false;
    
    return true;
}

int gcd(int a, int b)
{
    if (!a) return b;
    return gcd(b%a,a);
}

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    cin >> n;
    FOR (i,0,n)
    FOR (j,0,n)
    cin >> a[i][j];
    
    int val = a[0][1];
    FOR (i,2,n)
    {
        val = gcd(val,a[0][i]);
    }
    
    FOR (x,1,val+1)
    {
        if (x*x > a[0][1]) break;
        if (a[0][1]%x != 0) continue;
        if (check(x))
        {
            FOR (i,0,n) cout << ans[i]<<" ";
            return 0;
        }
        
        if (check(a[0][1]/x))
        {
            FOR (i,0,n) cout << ans[i]<<" ";
            return 0;
        }
    }
}