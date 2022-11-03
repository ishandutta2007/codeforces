#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 311;

mt19937 rnd(0);

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(l), b(r), ca(n, 0), cb(n, 0);
    for(int i = 0; i < l; i++) {
        cin >> a[i];
        a[i]--;
        ca[a[i]]++;
    }

    for(int i = 0; i < r; i++) {
        cin >> b[i];
        b[i]--;
        cb[b[i]]++;
    }

    if(l < r) {
        swap(l, r);
        swap(a, b);
        swap(ca, cb);
    }

    int ans = (l - r) / 2;

    int cnt = 0;
    int cr = 0;
    for(int i = 0; i < n; i++) {
        int d = min(ca[i], cb[i]);
        ca[i] -= d;
        cb[i] -= d;
        cnt += ca[i] / 2;
        cr += cb[i];
    }

    ans += cr;
    ans += max(0, (l - r) / 2 - cnt);

//    cout << "dg " << (l - r) / 2 << ' ' << cr << ' ' << cnt << endl;

//    if(cnt <= (l - r) / 2) {
//        cout << ans << endl;
//        return;
//    }
//
//    ans += cr - cnt;

    cout << ans << endl;


}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}