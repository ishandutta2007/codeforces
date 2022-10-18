#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& x : v)
            cin >> x;
        vector<int> cnt(30);
        for (int x : v) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((x >> bit) % 2)
                    ++cnt[bit];
            }
        }
        int g = 0;
        for (int x : cnt)
            g = gcd(g, x);
        //for (int x : cnt) cerr << x << ' '; cerr << endl;
        for (int i = 1; i <= n; ++i)
            if (g % i == 0)
                cout << i << ' ';
        cout << '\n';
    }
}