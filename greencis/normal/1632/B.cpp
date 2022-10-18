//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
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
        int high = -1;
        for (int i = 0; i < 30; ++i)
            if ((n - 1) & (1 << i)) high = i;

        vector<int> v;
        for (int i = 1; i < (1 << high); ++i) v.push_back(i);
        v.push_back(0);
        for (int i = (1 << high); i < n; ++i) v.push_back(i);

        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
}