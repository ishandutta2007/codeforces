#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

int get(const vector<int> &b, int a, int x) {
    int l = -1, r = b.size();
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(b[m] - a >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int m = 6;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    int ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x = b[i] - a[j];

            if(b[0] - a[0] < x)
                continue;


            int lst = n;
            int mx = 0;
            for(int l = m - 1; l >= 0 && lst > 0; l--) {
                int ind = get(b, a[l], x);
                mx = max(mx, b[lst - 1] - a[l]);
                lst = ind;

//                if(l == 0 && ind > 0) {
//                    mx = INF;
//                }
            }
//            cout <<x << ' ' << mx << endl;
            ans = min(ans, mx - x);
        }
    }

    cout << ans << endl;
}