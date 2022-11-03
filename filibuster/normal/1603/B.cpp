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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;



/*
4 6
1 2
2 3
3 4
1 4
4 3
3 2
*/

void solve() {
    int x, y;
    cin >> x >> y;

    if(x > y) {
        cout << x + y << '\n';
        return;
    }

    if(x == y) {
        cout << x << '\n';
        return;
    }

    if(y % x == 0) {
        cout << y << '\n';
        return;
    }

    int n = y - (y % x) / 2;

    if(n % x == y % n) {
        cout << n << '\n';
    } else {
        cout << (x + y) / 2 << '\n';
    }
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