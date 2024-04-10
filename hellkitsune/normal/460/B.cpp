#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

LL x;
int a, b, c;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    for (int i = 1; i <= 81; ++i) {
        x = i;
        for (int j = 1; j < a; ++j)
            x *= i;
        x *= b;
        x += c;
        if (x <= 0 || x >= 1000000000)
            continue;
        int sum = 0;
        int xx = x;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        if (sum == i) ans.pb(xx);
    }
    cout << (int)ans.size() << endl;
    REP(i, ans.size()) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}