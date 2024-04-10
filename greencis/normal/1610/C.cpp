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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        int L = 1, R = n;
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            int sz = 0;
            for (int i = 0; sz < mid && i < n; ++i) {
                if (b[i] >= sz && a[i] >= mid - 1 - sz)
                    ++sz;
            }
            if (sz == mid)
                L = mid;
            else
                R = mid - 1;
        }
        cout << L << endl;
    }
}