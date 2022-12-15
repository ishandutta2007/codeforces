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
 
LL a[7777];
LL b[7777];
int sz[77];
int NUM[7000];
 
int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    int n;
    cin >> n;
    FOR (i,0,n) cin >> a[i];
    
    LL res = 0;
    FOR (i,0,n) {cin >> b[i]; res += b[i];}
    
    FOR (i,0,n)
    {
        FOR (j,0,n)
        {
            if ((a[i]|a[j]) != a[j])
                NUM[i]++;
        }
    }
    
    int sz = n-1;
    FOR (step,0,n)
    {
        FOR (i,0,n)
        {
            if (sz == NUM[i])
            {
                NUM[i] = -2;
                res -= b[i];
                sz--;
                FOR (j,0,n)
                {
                    if ((a[j]|a[i]) != a[i])
                        NUM[j]--;
                }
            }
        }
    }
    
    
    cout << res;
}