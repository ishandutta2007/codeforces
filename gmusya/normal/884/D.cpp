#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    multiset<ll> set;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        set.insert(x);
    }
    ll ans = 0;
    while (set.size() != 1) {
        if (set.size() & 1) {
            ll a = *set.begin();
            set.erase(set.begin());
            ll b = *set.begin();
            set.erase(set.begin());
            ll c = *set.begin();
            set.erase(set.begin());
            ans += a + b + c;
            set.insert(a + b + c);
        } else {
            ll a = *set.begin();
            set.erase(set.begin());
            ll b = *set.begin();
            set.erase(set.begin());
            ans += a + b;
            set.insert(a + b);
        }
    }
    cout << ans;
}