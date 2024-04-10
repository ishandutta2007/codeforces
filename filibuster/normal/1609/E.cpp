#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = 113;

//struct Node {
//    vector<int> dp;
//
//    Node() {
//        dp.resize(32, INF);
//    }
//
//    Node(int x) {
//        dp.resize(32, INF);
//        for(int i = 0; i < 3; i++)
//            dp[1 << i] = 1;
//        dp[1 << x] = 0;
//    }
//};

/*
0 - nothing
1 - a
2 - b
3 - c
4 - a and b
5 - a and c
6 - b and c
7 - ab
8 - bc
*/

int dp[N * 4][32];

inline void merge(int v) {
    for(int i = 0; i < 32; i++) {
        dp[v][i] = INF;
    }

    int v1 = v * 2 + 1, v2 = v * 2 + 2;

    for(int ma = 0; ma < 32; ma++) {
        for(int mb = 0; mb < 32; mb++) {
            int mask = ma | mb;

            if((ma & 1) && (mb & 16) || (ma & 8) && (mb & 4))
                continue;

            if((ma & 1) && (mb & 2))
                mask |= 8;

            if((ma & 2) && (mb & 4))
                mask |= 16;

            dp[v][mask] = min(dp[v][mask], dp[v1][ma] + dp[v2][mb]);

//            if((mask & 8) && )
        }
    }
//    return res;

//    for(int al = 0; al < 3; al++) {
//        for(int ar = al; ar < 3; ar++) {
//            for(int bl = 0; bl < 3; bl++) {
//                for(int br = 0; br < 3; br++) {
//                    res.dp[z]
//                }
//            }
//        }
//    }
}

/*
9 5
aaabccccc
4 a
4 b
2 b
5 a
1 b

9 0
bbabacccc


3 0
abc
*/

string s;

//Node t[4 * N];

void build(int v, int l, int r) {
    if(r - l == 1) {
        int x = s[l] - 'a';
        for(int i = 0; i < 32; i++) {
            dp[v][i] = INF;
        }

        dp[v][1] = dp[v][2] = dp[v][4] = 1;
        dp[v][1 << x] = 0;
//        t[v] = Node(x);

//        cout << "build " << v << ' ' << l << ' ' << r << "  ------------ " << endl;
//        for(int i = 0; i < 32; i++) {
//            cout << i << ' ' << dp[v][i] << endl;
//        }
//        for(int i = 0; i <= 8; i++)
//            t[v].dp[i] = 1;
//        t[v].dp[x] = 0;
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

//    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    merge(v);

//    cout << "build " << v << ' ' << l << ' ' << r << endl;
//    for(int i = 0; i < 32; i++) {
//        cout << i << ' ' << dp[v][i] << endl;
//    }
}

void upd(int v, int l, int r, int i, char c) {
    if(i < l || i >= r)
        return;

    if(r - l == 1) {
        s[l] = c;
        int x = s[l] - 'a';
        for(int i = 0; i < 32; i++) {
            dp[v][i] = INF;
        }

        dp[v][1] = dp[v][2] = dp[v][4] = 1;
        dp[v][1 << x] = 0;
//        for(int i = 0; i <= 8; i++)
//            t[v].dp[i] = 1;
//        t[v].dp[x] = 0;
        return;
    }

    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, i, c);
    upd(v * 2 + 2, m, r, i, c);

    merge(v);
//    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

int get() {
    int ans = INF;

    for(int x = 0; x < 32; x++)
        ans = min(ans, dp[0][x]);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    cin >> s;

    build(0, 0, n);

//    cout << get() << endl;

    for(int i = 0; i < q; i++) {
        int ind;
        char c;
        cin >> ind >> c;

        upd(0, 0, n, ind - 1, c);



        cout << get() << '\n';
    }

//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();
}