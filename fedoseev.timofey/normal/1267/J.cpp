#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define elif else if
#define int long long
#define free ferer465346
#define rt return
const int BINF = 9e8, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
const int MAXN = 1e6;
void solve() {
    map<int, int> cnt;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mn = 1e9;
    for (pair<int, int> pr : cnt)
        mn = min(mn, pr.second);
    vector<bool> ok(mn + 1, 1);
    for (pair<int, int> pr : cnt) {
        for (int s = 1; s <= mn; ++s) 
            if (!(pr.y % s <= pr.y / s || pr.y % (s + 1) == 0))
                ok[s] = 0;
    }
    int anss = 0;
    for (int i = 0; i < ok.size(); ++i)
        if (ok[i])
            anss = i;
    int ans = 0;
    for (pair<int, int> pr : cnt) 
        ans += (pr.y + anss) / (anss + 1);
    cout << ans << "\n";
    return;
}
signed main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
 
    return 0;
}