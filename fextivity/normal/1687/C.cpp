#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
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

const int N = 2e5 + 5;

int n, m;
int a[N], b[N];
pii c[N];

int dif[N]; ll prefdif[N];

vi vc[N];
set <int> sttprefdif;
queue <int> qu;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    ForE(i, 1, m){
        cin >> c[i].fi >> c[i].se;
    }

    ForE(i, 1, n){
        dif[i] = a[i] - b[i];
        prefdif[i] = prefdif[i - 1] + dif[i];
    }
    if (prefdif[n] != 0){
        cout << "NO" << endl;
        continue;
    }

    sttprefdif.clear();
    ForE(i, 0, n){
        vc[i].clear();
        if (prefdif[i] != 0){
            sttprefdif.emplace(i);
        }
    }
    while (!qu.empty()){
        qu.pop();
    }
    ForE(i, 1, m){
        vc[c[i].fi - 1].emplace_back(i);
        vc[c[i].se].emplace_back(i);
        if (prefdif[c[i].fi - 1] == 0 and prefdif[c[i].se] == 0){
            qu.emplace(i);
        }
    }
    while (!qu.empty() and !sttprefdif.empty()){
        int i = qu.front(); qu.pop();
        auto itr = sttprefdif.lower_bound(c[i].fi);
        while (itr != sttprefdif.end() and (*itr) < c[i].se){
            int j = *itr;
            prefdif[j] = 0;
            Fora(ti, vc[j]){
                if (prefdif[c[ti].fi - 1] == 0 and prefdif[c[ti].se] == 0){
                    qu.emplace(ti);
                }
            }
            itr = sttprefdif.erase(itr);
        }
    }
    if (sttprefdif.empty()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
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