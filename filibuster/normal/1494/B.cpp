#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

/*

*/

void solve() {
    int n, u, r, l, d;
    cin >> n >> u >> r >> d >> l;

    int ur = -1, ul= -1, dl = -1, dr = -1;
    for(ur = 0; ur < 2; ur++) {
        for(ul = 0; ul < 2; ul++) {
            for(dl = 0; dl < 2; dl++) {
                for(dr = 0; dr < 2; dr++) {
                    if(ul + ur <= u && u <= n - 2 + ul + ur &&
                       dl + dr <= d && d <= n - 2 + dl + dr &&
                       dl + ul <= l && l <= n - 2 + dl + ul &&
                       dr + ur <= r && r <= n - 2 + dr + ur) {
                            cout << "YES" << endl;
                            return;
                       }
                }
            }
        }

    }

    cout << "NO" << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}