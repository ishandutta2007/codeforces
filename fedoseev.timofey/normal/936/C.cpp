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

void modify(string &s, int x) {
    string tmp = s.substr(s.size() - x, x);
    reverse(tmp.begin(), tmp.end());
    s = tmp + s.substr(0, s.size() - x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    string t, s;
    cin >> n >> t >> s;
    int ok = 0;
    vector <int> ans;
    while (ok < n) {
        char c = s[ok];
        int uk = -1;
        for (int i = 0; i + ok < n; ++i) {
            if (t[i] == c) {
                uk = i;
                break;
            }
        }
        if (uk == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(n - uk - 1);
        ans.push_back(1);
        ans.push_back(n);
        modify(t, n - uk - 1);
        modify(t, 1);
        modify(t, n);
        ++ok;
    }
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e << " ";
    }
    cout << endl;
}