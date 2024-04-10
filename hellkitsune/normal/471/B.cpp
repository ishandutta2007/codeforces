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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
PII a[2000];
vector<int> ans1, ans2, ans3;

int main() {
    cin >> n;
    REP(i, n) cin >> a[i].first, a[i].second = i + 1;
    sort(a, a + n);
    REP(i, n) ans1.pb(a[i].second);
    bool flag = false;
    REP(i, n - 1) if (a[i].first == a[i + 1].first) {
        swap(a[i], a[i + 1]);
        if (flag) REP(i, n) ans3.pb(a[i].second);
        else REP(i, n) ans2.pb(a[i].second);
        if (!flag) flag = true;
        else {
            cout << "YES\n";
            REP(i, n) cout << ans1[i] << ' ';
            cout << endl;
            REP(i, n) cout << ans2[i] << ' ';
            cout << endl;
            REP(i, n) cout << ans3[i] << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}