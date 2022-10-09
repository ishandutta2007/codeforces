#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> who;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        who[a[i]]++;
    }
    int l = 0, r = n + 2;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = mid;
        for (auto i : who) {
            if (i.first < mid) {
                --cnt;
            }
        }
        if (cnt <= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    multiset<int> s;
    for (auto i : who) {
        if (i.first >= l) {
            s.insert(i.second);
        }
    }
    int ans = s.size();
    while (s.size() && k >= *s.begin()) {
        k -= *s.begin();
        --ans;
        s.erase(s.begin());
    }
    cout << ans << '\n';
}

int main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

   SOLVE
}