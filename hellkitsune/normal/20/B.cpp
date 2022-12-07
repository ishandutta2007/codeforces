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

LL a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "-1\n";
            else cout << "0\n";
        } else {
            cout << "1\n";
            cout << setprecision(12) << fixed << (double)-c / b << '\n';
        }
        return 0;
    }
    LL d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "0\n";
    } else if (d == 0) {
        cout << "1\n";
        cout << setprecision(12) << fixed << (-b * 0.5) / a << '\n';
    } else {
        cout << "2\n";
        vector<double> ans;
        ans.pb((0.5 / a) * (-b - sqrt((double)d)));
        ans.pb((0.5 / a) * (-b + sqrt((double)d)));
        sort(ans.begin(), ans.end());
        REP(i, 2)
            cout << setprecision(12) << fixed << ans[i] << '\n';
    }
    return 0;
}