#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

bool check(long long now, multiset<long long> &a) {
    if (a.count(now)) {
        a.erase(a.find(now));
        return true;
    }
    if (now == 1)
        return false;
    if (check(now / 2, a) && check(now - now / 2, a))
        return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    multiset<long long> a;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        a.insert(c);
        sum += c;
    }
    check(sum, a);
    if (a.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}


signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    SOLVE
}