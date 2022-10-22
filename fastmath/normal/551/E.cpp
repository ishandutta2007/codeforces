#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1 << 20;
const int INF = 1e16 + 7;

int n, q;
int a[MAXN];

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
}

const int K = 1 << 10;

int add[K];
unordered_map <int, signed> ms[K];

void build() {
    for (int i = n; i < MAXN; ++i) {
        a[i] = INF;
    }   
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            ms[i][a[i * K + j]]++;
        }   
    }   
}   

void solve() {
    build();
}

void upd(int l, int r, int x) {
    for (int i = 0; i < K; ++i) {
        int tl = i * K;
        int tr = tl + K - 1;
        if (l <= tl && tr <= r) {
            add[i] += x;
        }
        else if (tr < l || r < tl) {
            continue;
        }   
        else {
            for (int t = tl; t <= tr; ++t) {
                if (l <= t && t <= r) {
                    ms[i][a[t]]--;
                    if (ms[i][a[t]] == 0) {
                        ms[i].erase(a[t]);
                    }   
                    a[t] += x;
                    ms[i][a[t]]++;
                }   
            }   
        }   
    }   
}

int getl(int x) {
    for (int i = 0; i < K; ++i) {
        int tl = i * K;
        int tr = tl + K - 1;
        if (ms[i].find(x - add[i]) != ms[i].end() && ms[i][x - add[i]]) {
            for (int t = tl; t <= tr; ++t) {
                if (a[t] == x - add[i]) {
                    return t;
                }   
            }   
            cout << "KIKOS\n";
            exit(1);
        }   
    }   
    return -1;
}   

int getr(int x) {
    for (int i = K - 1; i >= 0; --i) {
        int tl = i * K;
        int tr = tl + K - 1;
        if (ms[i].find(x - add[i]) != ms[i].end() && ms[i][x - add[i]]) {
            for (int t = tr; t >= tl; --t) {
                if (a[t] == x - add[i]) {
                    return t;
                }   
            }   
            cout << "KIKOS\n";
            exit(1);
        }   
    }   
    return -1;
}   

void print() {
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l; --r;
            upd(l, r, x);
        }
        else {
            int x;
            cin >> x;

            int l = getl(x);
            int r = getr(x);

            if (l == -1) {
                cout << "-1\n";
            }   
            else {
                cout << r - l << '\n';
            }   
        }   
    }   
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}