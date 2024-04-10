#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

map <int, int> par, cnt, dp;

int root(int p) {
    if (par[p] == p) return p;
    else return root(par[p]);    
}

int getdp(int p) {
    if (par[p] == p) return 0;
    else return dp[p] ^ getdp(par[p]);
}

bool check(int l, int r) {
    if (par.find(l) == par.end()) return 0;
    if (par.find(r) == par.end()) return 0;
    return root(l) == root(r);
}

int get(int l, int r) {
    return getdp(l) ^ getdp(r);
}

void add(int l, int r, int x) {
    //cout << "add " << l << ' ' << r << ' ' << x << '\n';
    if (par.find(l) == par.end()) {
        par[l] = l;
        cnt[l] = 1;
        dp[l] = 0;
    }
    if (par.find(r) == par.end()) {
        par[r] = r;
        cnt[r] = 1;
        dp[r] = 0;
    }
    int lx = getdp(l);
    int rx = getdp(r);
    l = root(l);
    r = root(r);
    //dp[l] ^ dp[r] ^ new = x
    int nx = lx ^ rx ^ x;
    if (cnt[l] < cnt[r]) {
        par[l] = r;
        cnt[r] += cnt[l];
        dp[l] = nx;
    }   
    else {
        par[r] = l;
        cnt[l] += cnt[r];
        dp[r] = nx;
    }   
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last; r ^= last; x ^= last;
            if (r < l) swap(l, r);
            //cout << t << ' ' << l << ' ' << r << ' ' << x << '\n';
            ++r;
            if (check(l, r)) continue;
            add(l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l ^= last; r ^= last;
            if (r < l) swap(l, r);
            //cout << t << ' ' << l << ' ' << r << '\n';
            ++r;
            if (!check(l, r)) {
                cout << "-1\n";
                last = 1;
            }
            else {
                last = get(l, r);
                cout << last << '\n';
            }
        }   
    }

    return 0;
}