#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    set<int> l, mid, r;
    int ans = 1;
    while (t--) {
        string s;
        int p;
        cin >> s >> p;
        if (s == "ADD") {
            if (l.size() && *l.rbegin() > p) {
                l.insert(p);
            } else if (r.size() && *r.begin() < p) {
                r.insert(p);
            } else
                mid.insert(p);
        } else {
            if (l.find(p) != l.end()) {
                if (*l.rbegin() != p)
                    cout << 0, exit(0);
                l.erase(p);
                for (int x : mid)
                    r.insert(x);
                mid.clear();
            } else if (r.find(p) != r.end()) {
                if (*r.begin() != p)
                    cout << 0, exit(0);
                r.erase(p);
                for (int x : mid)
                    l.insert(x);
                mid.clear();
            } else {
                ans = ans * 2 % mod;
                for (auto x : mid)
                    if (x < p)
                        l.insert(x);
                    else if (x > p)
                        r.insert(x);
                mid.clear();
            }
        }
    }
    ans = ans * ll(mid.size() + 1) % mod;
    cout << ans;
}