#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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

const int N = 1e3 + 5;

int n, m;
vi a;

vpii vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        int x; cin >> x; a.emplace_back(x);
    }

    sort(bend(a));

    while (!a.empty()){
        int x = a.back(); a.pop_back();
        if (3 * x <= m){
            vans.emplace_back(3 * x, 2 * x);
            continue;
        }
        if (2 * x + 1 > m){
            cout << -1 << endl;
            return 0;
        }
        bool ck = 0;
        FordE(i, isz(a) - 1, 0){
            int y = a[i];
            if (x % y != 0 or x == y){
                continue;
            }
            if (2 * x + y > m){
                continue;
            }
            vans.emplace_back(2 * x + y, x + y);
            a.erase(a.begin() + i);
            ck = 1;
            break;
        }
        if (!ck){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi << ' ' << elem.se << endl;
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