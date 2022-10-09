#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] == i) {
                ans.push_back((j + 1) % i);
                vector<int> b(n);
                for (int k = 0; k < i; ++k) {
                    b[(k - j - 1 + i) % i] = a[k];
                }
                a = b;
                break;
            }
        }
    }
    reverse(all(ans));
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
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