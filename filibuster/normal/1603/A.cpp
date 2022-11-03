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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        bool fl = false;
        for(int j = i + 2; j >= 2; j--) {
            if(a[i] % j != 0) {
                fl = true;
                break;
            }
        }

        if(!fl) {
            cout << "NO" << '\n';
            return;
        }
    }

//    set<int> st;
//    for(int i = 0; i < n; i++) {
//        st.insert(i);
//    }
//
//    for(int i = 0; i < n; i++) {
//        auto it = st.end();
//        bool fl = false;
//
//        while(it != st.begin()) {
//            it--;
//
//            if(a[*it] % (*it + 2) != 0) {
//                st.erase(it);
//                fl = true;
//                break;
//            }
//        }
//
//        if(!fl) {
//            cout << "NO" << '\n';
//            return;
//        }
//
////        cout << i << endl;
////        for(auto x : st)
////            cout << x << ' ';
////        cout << endl;
//    }
//
    cout << "YES" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}