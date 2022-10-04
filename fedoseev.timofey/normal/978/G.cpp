#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

struct exam {
    int s, d, c;
    exam() {
        cin >> s >> d >> c;
        --s, --d;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <exam> a(m);
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        bool flag = 0;
        for (int j = 0; j < m; ++j) {
            if (a[j].d == i) {
                if (a[j].c != 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                flag = 1;
                ans[i] = m + 1;
                break;
            }
        }
        if (!flag) {
            int who = -1;
            for (int j = 0; j < m; ++j) {
                if (a[j].s <= i && i < a[j].d && a[j].c) {
                    if (who == -1 || a[who].d > a[j].d) {
                        who = j;
                    }
                }
            }
            if (who == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = who + 1;
                --a[who].c;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}