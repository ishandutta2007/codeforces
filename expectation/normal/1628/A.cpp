#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int i = (a)-1; (i) >= (b); --(i))
#define For(i, a, b) for (int i = (a); i < (b); ++(i))
#define FoR(i, a, b) for (int i = (a)-1; (i) >= (b); --(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000001
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define x first
//#define __float128 long double
#define y second

int n, t;
int a[300000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed; cout.precision(10);
    
    cin >> t;
    FOR (tst,0,t) {
        cin >> n;
        map<int, int> f;
        vector<int> ans;
        FOR (i,0,n) {
            cin >> a[i];
            f[a[i]]++;
        }
        int pos = 0;
        while (pos < n) {
            int num = 0;
            while (f.count(num) && f[num] > 0) num++;
            ans.PB(num);
            set<int> g;
            while (g.size() != max(num,1)) {
                if (a[pos] < num || num == 0) g.insert(a[pos]);
                f[a[pos]]--;
                pos++;
            }
        }
        cout << ans.size() << "\n";
        FOR (i,0,ans.size()) cout << ans[i]<<" "; cout << "\n";
    }
    return 0;
}