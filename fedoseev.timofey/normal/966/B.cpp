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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector <pair <int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < n; ++i) {
        {
            int cnt = (x1 + c[i].first - 1) / c[i].first;
            if (cnt < i + 1) {
                int scount = i + 1 - cnt;
                int last = c[scount - 1].first;
                if (x2 <= (ll)scount * last) {
                    vector <int> f, s;
                    for (int j = 0; j < scount; ++j) {
                        s.push_back(c[j].second + 1);
                    }
                    for (int j = scount; j <= i; ++j) {
                        f.push_back(c[j].second + 1);
                    }
                    cout << "Yes\n" << f.size() << ' ' << s.size() << '\n';
                    for (int i = 0; i < f.size(); ++i) {
                        cout << f[i] << ' ';
                    }
                    cout << '\n';
                    for (int i = 0; i < s.size(); ++i) {
                        cout << s[i] << ' ';
                    }
                    cout << '\n';
                    return 0;
                }
            }
        }
        {
            swap(x1, x2);
            int cnt = (x1 + c[i].first - 1) / c[i].first;
            if (cnt < i + 1) {
                int scount = i + 1 - cnt;
                int last = c[scount - 1].first;
                if (x2 <= (ll)scount * last) {
                    vector <int> f, s;
                    for (int j = 0; j < scount; ++j) {
                        s.push_back(c[j].second + 1);
                    }
                    for (int j = scount; j <= i; ++j) {
                        f.push_back(c[j].second + 1);
                    }
                    swap(s, f);
                    cout << "Yes\n" << f.size() << ' ' << s.size() << '\n';
                    for (int i = 0; i < f.size(); ++i) {
                        cout << f[i] << ' ';
                    }
                    cout << '\n';
                    for (int i = 0; i < s.size(); ++i) {
                        cout << s[i] << ' ';
                    }
                    cout << '\n';
                    return 0;
                }
            }
            swap(x1, x2);
        }
    }
    cout << "No\n";
}