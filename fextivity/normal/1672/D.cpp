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
int a[N], b[N];

vi vposa[N];
int cnt[N];

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
        cin >> b[i];
    }

    ForE(i, 1, n){
        vposa[i].clear();
        cnt[i] = 1;
    }
    ForE(i, 1, n){
        vposa[a[i]].emplace_back(i);
    }
    ForE(i, 1, n){
        reverse(bend(vposa[i]));
    }
    set <int> stt;
    ForE(i, 1, n){
        stt.insert(i);
    }

    bool ans = 1;
    ForE(i, 1, n){
        while (1){
            if (stt.empty()){
                ans = 0;
                break;
            }
            int idx = *stt.begin(); int val = a[idx];
            if (val == b[i]){
                cnt[idx]--;
                if (cnt[idx] == 0){
                    vposa[val].pop_back();
                    stt.erase(idx);
                }
                break;
            }
            vposa[val].pop_back();
            if (vposa[val].empty()){
                ans = 0;
                break;
            }
            int tidx = vposa[val].back();
            cnt[tidx] += cnt[idx];
            stt.erase(idx);
        }
        if (!ans){
            break;
        }
    }
    if (ans){
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