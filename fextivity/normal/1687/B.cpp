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

const int N = 2e2 + 5, M = 5e2 + 5;

int query(const string &s){
    cout << "? " << s << endl;
    int ans; cin >> ans; return ans;
}

int answer(int ans){
    cout << "! " << ans << endl;
    exit(0);
}

int n, m;

string s;
pii a[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    s = string(m, '0');
    For(i, 0, m){
        s[i] = '1';
        a[i] = make_pair(query(s), i);
        s[i] = '0';
    }
    sort(a, a + m);
    int prevval = 0, ans = 0;
    For(i, 0, m){
        s[a[i].se] = '1';
        int val = query(s);
        if (val - prevval == a[i].fi){
            ans += a[i].fi;
        }
        prevval = val;
    }
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