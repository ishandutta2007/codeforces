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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set <char> have;  
    for (auto c : s) {
        have.insert(c);
    }
    if (k > s.size()) {
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            ans += s[i];
        }
        for (int i = s.size(); i < k; ++i) {
            ans += *have.begin();
        }
        cout << ans << endl;
        return 0;
    }
    int r = k - 1;
    string ans;
    while (have.upper_bound(s[r]) == have.end()) --r;
    for (int i = 0; i < r; ++i) {
        ans += s[i];
    }
    ans += *have.upper_bound(s[r]);
    for (int i = r + 1; i < k; ++i) {
        ans += *have.begin();
    }
    cout << ans << endl;
}