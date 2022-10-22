#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e3 + 5;

int solve(vi a, int x){
    int l = 0, ans = 0;
    while (l < isz(a)){
        ans++;
        int r = l, y = a[l];
        if (y > x){
            return 0;
        }
        while (r + 1 < isz(a) and y + 1 + a[r + 1] <= x){
            r++; y += 1 + a[r];
        }
        l = r + 1;
    }
    return ans;
}

map <int, int> mpp;

int query(int x){
    if (mpp.count(x)){
        return mpp[x];
    }
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    // ans = solve(vi({5, 2, 7, 3, 5, 6}), x);
    // cout << ans << endl;
    return (mpp[x] = ans);
}

void answer(int x){
    cout << "! " << x << endl;
    exit(0);
}

int n;
int a[N];

ll ans = LLONG_MAX;

void solve(int l, int r, int lo, int hi){
    if (l > r or lo > hi){
        return;
    }
    if ((ll)l * lo > ans){
        return;
    }
    // cout << "solve " << l << ' ' << r << ' ' << lo << ' ' << hi << endl;
    if (lo == hi){
        ForE(i, l, r){
            a[i] = lo;
            ans = min(ans, (ll)i * a[i]);
        }
        return;
    }
    int mid = (lo + hi) >> 1;
    int h = query(mid);
    if (h == 0){
        h = n + 1;
    }
    solve(l, h - 1, mid + 1, hi);
    solve(h, r, lo, mid);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    solve(1, n, 1, n * 2000);
    answer(ans);
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/