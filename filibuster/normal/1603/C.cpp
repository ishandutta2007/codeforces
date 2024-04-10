//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 100;
const int K = 400;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
4 6
1 2
2 3
3 4
1 4
4 3
3 2
*/

int t[N];

void add(int i, int x) {
    for( ; i < N; i |= (i + 1))
        t[i] += x;
}

int get(int i) {
    int res = 0;
    for( ; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

/*
1
3
5 4 3
*/

int get(int l, int r) {
    return (l == 0 ? get(r - 1) : get(r - 1) - get(l - 1));
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    int res = 0;
    vector<pii> cur;
    for(int i = n - 1; i >= 0; i--) {
//        cout << i << endl;
//        for(auto x : cur)
//            cout << "cur " << x.f << ' ' << x.s << endl;
//        cout << endl;
        int j = 0;
        vector<pii> b;
        b.emplace_back(a[i], 1);
        for(int k = 1; k < B; k++) {
            int cnt = 0;
            while(j < cur.size() && (a[i] + k - 1) / k <= cur[j].f) {
                cnt += cur[j].s;
                j++;
            }

//            if(k < 10)
//                cout << k << ' ' << cnt << ' ' << j << endl;

            res = sum(res, mul(cnt, k - 1));
            if(cnt > 0) {
                int x = (a[i]) / k;
                if(b.back().f == x)
                    b.back().s += cnt;
                else
                    b.emplace_back(x, cnt);
            }

        }

        for( ; j < cur.size(); j++) {
//            cout << "for2 " << j << endl;
            int k = max(1,  a[i] / cur[j].f);
            while((a[i] + k - 1) / k > cur[j].f)
                k++;

//            cout << k << endl;

            res = sum(res, mul(cur[j].s, k - 1));
            int x = (a[i]) / k;
            if(b.back().f == x)
                b.back().s += cur[j].s;
            else
                b.emplace_back(x, cur[j].s);
//            b.emplace_back((a[i] + k - 1) / k, cur[j].s);
        }



        ans = sum(res, ans);
        cur = b;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

//    int x, y;
////    cin >> x >> y;
//    cin >> x;

//    for(int n = 1; n < 1000000; n++) {
//        if(n % x == y % n) {
//            cout << n << endl;
//        }
//    }
//
//    for(int y = x; y < 100; y += 2) {
//        cout << "-------------- " << y << endl;
//        for(int n = 1; n < 1000000; n++) {
//            if(n % x == y % n) {
//                cout << n << endl;
//            }
//        }
//    }
//    int mx = 0;
//    for(int x = 2; x <= 100; x += 2) {
//        for(int y = x + 2; y <= 100; y += 2) {
//            int mn = INF;
//            int cnt = 0;
//            for(int n = 1; n <= y; n++) {
//                if(n % x == y % n) {
//                    mn = min(mn, y - n);
//                    cnt++;
////                    cout << n << endl;
//                }
//            }
//
//            int n1 = (x + y) / 2;
//            int n2 = y - (y % x) / 2;
//            if(n1 % x != y % n1 && n2 % x != y % n2) {
//                cout << x << ' ' << y << ' ' << mn << " : ";
//                for(int n = 1; n <= y; n++) {
//                    if(n % x == y % n) {
//                        cout << n << ' ';
//                    }
//                }
//                cout << endl;
//            }
////            if(cnt == 1)
////                cout << x << ' ' << y - mn << ' ' << y << ' ' << (x + y) / 2 << endl;
//            mx = max(mx, mn);
//        }
//    }
//
//    cout << mx << endl;
}