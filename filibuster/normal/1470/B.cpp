#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 3e5 + 12;
const int A = 1e6 + 13;

int sum(int a, int b, int m) {
    a += b;
    if(a >= m)
        a -= m;
    return a;
}

int a[N];
int p = 41;
vector<int> h[A];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
//        p[i].erase(p[i].begin(), p[i].end());
    }

    map<vector<int>, int> mp;

    for(int i = 0; i < n; i++) {
        mp[h[a[i]]]++;
    }

    int mx = 0, sq0 = 0, sq1 = 0, sq2 = 0;
    for(auto pp : mp) {
//        cout << pp.f << ' ' << pp.
        if(pp.f.empty()) {
            sq0 += pp.s;
        }
        mx = max(mx, pp.s);
        if(pp.s % 2 == 0 || pp.f.empty())
            sq1 += pp.s;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        li w;
        cin >> w;

        if(w == 0) {
            cout << mx << '\n';
        } else {
            cout << max(mx, sq1) << '\n';
        }
    }
}

int d[A];

/*
1
5
240 934 761 964 380
1
0

1
5
40 34 61 64 80
1
0

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < A; i++) {
        if(d[i] == 0) {
            d[i] = i;
            if(i * 1ll * i < A)
                for(int j = i * i; j < A; j += i)
                    d[j] = i;
        }
    }

    for(int i = 2; i < A; i++) {
        set<int> st;
        int x = i;
        while(x > 1) {
            if(st.count(d[x]))
                st.erase(d[x]);
            else
                st.insert(d[x]);
            x /= d[x];
        }
        for(auto y : st) {
            h[i].push_back(y);
        }
//        int pw1 = 1, pw2 = 1;
//        for(auto y : st) {
//            h[i].f = sum(h[i].f, y * 1ll * pw1 % M1, M1);
//            h[i].s = h[i].s ^ y;//sum(h[i].s, y * 1ll * pw2 % M2, M2);
//            pw1 = pw1 * 1ll * p % M1;
//            pw2 = pw2 * 1ll * p % M2;
//        }
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}