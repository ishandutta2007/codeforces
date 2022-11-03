#include <bits/stdc++.h>

#define f first
#define s second
#define int long long

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const li INF = 3e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
7 400000
0 1
0 5
0 6
1 2
1 4
2 3

*/

li get(li n, li m) {
    li res = 0;
    if(ld(m) * n > INF)
        return INF;
    for(int i = 0; i < min(n, m); i++) {
        res += (n - i) * 1ll * (m - i);
        if(res >= INF)
            return INF;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    cout << get(1000000000, 1000000) << endl;

    li x;
    cin >> x;

    set<pii> st;
    for(int n = 1; ; n++) {
        li k = n * n - n * (n - 1) / 2;
        li b = x + n * n * (n - 1) / 2 - n * (n - 1) * (2 * n - 1) / 6;

        if(b / k < n)
            break;

//        if(n == 3) {
//            cout << k << ' ' << b << endl;
//
//        }
        if(b % k == 0) {
            st.insert({n, b / k});
        }
    }

    set<pii> st1;
    for(auto p : st) {
        st1.insert(p);
        swap(p.f, p.s);
        st1.insert(p);
    }

    cout << st1.size() << '\n';
    for(auto p : st1)
        cout << p.f << ' ' << p.s << '\n';
}