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

int n;
int a[N];

vi vpos[N];
int b[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        vpos[i].clear();
    }
    map <int, int> mpp;
    ForE(i, 1, n){
        mpp[a[i]]++;
        vpos[a[i]].emplace_back(i);
    }
    while (isz(mpp)){
        vi vidx;
        Fora(&elem, mpp){
            vidx.emplace_back(vpos[elem.fi].back()); vpos[elem.fi].pop_back();
            elem.se--;
        }
        Fora(idx, vidx){
            if (vpos[a[idx]].empty()){
                mpp.erase(a[idx]);
            }
        }
        For(i, 0, isz(vidx)){
            int j = (i + 1) % isz(vidx);
            b[vidx[i]] = a[vidx[j]];
        }
    }
    ForE(i, 1, n){
        cout << b[i] << ' ';
    } cout << endl;
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