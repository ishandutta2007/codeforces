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
LL a[300000];
vector<LL> f[2000];

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);
    
    cin >> n;
    FOR (i,0,n)
    {
        LL a;
        cin >> a;
        LL x = a, ff = 0;
        while (x%2 == 0) x/=2, ff++;
        f[ff].PB(a);
    }
    
    int po = 0;
    FOR (i,0,70)
    if (f[po].size() < f[i].size())
        po = i;
    
    cout << n - f[po].size()<<"\n";
    FOR (i,0,70)
    if (i != po)
        FOR (j,0,f[i].size())
        cout << f[i][j]<<" ";
    
    
}