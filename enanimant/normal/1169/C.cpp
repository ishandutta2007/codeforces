// May 26, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = 0, hi = m - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        bool works = true;
        vector<int> b = a;
        if (b[0] + mid >= m) {
            b[0] = 0;
        }
        for (int i = 1; i < n; i++) {
            if ((b[i - 1] - b[i] + m) % m <= mid) {
                b[i] = b[i - 1];
            } else if (b[i] < b[i - 1]) {
                works = false;
            }
        }
        if (works) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';


    return 0;
}