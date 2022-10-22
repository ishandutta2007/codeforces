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

const int N = 1e6 + 5;

int n, m;
string s;

vi vans;
vi vdif;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    cin >> s;

    vans.clear();
    vdif.clear();

    vans.assign(n * m, 0);
    For(i, 0, n * m){
        vans[i] += i / m + 1;
    }
    For(i, 0, m){
        vans[i] += i + 1;
    }
    For(i, m, n * m){
        vans[i] += m;
    }

    vdif.assign(n * m, 0);
    int len = 0;
    For(i, 0, n * m){
        if (s[i] == '0'){
            len++;
            if (len == m){
                vdif[i]++;
            }
            if (len < m and len == i + 1){
                vdif[i]++;
                if (i + 1 < n * m){
                    vdif[i + 1]--;
                }
            }
        }
        else{
            if (len >= m){
                vdif[i]--;
            }
            len = 0;
        }
    }
    For(i, 0, n * m){
        if (i >= m){
            vdif[i] += vdif[i - m];
        }
    }
    For(i, 0, n * m){
        if (i >= 1){
            vdif[i] += vdif[i - 1];
        }
    }
    For(i, 0, n * m){
        vans[i] -= vdif[i];
    }

    For(i, 0, n * m){
        vdif[i] = 0;
    }
    For(i, 0, m){
        int cnt = 0;
        for (int j = i; j < n * m; j += m){
            if (s[j] == '1'){
                break;
            }
            cnt++;
        }
        if (cnt == 0){
            continue;
        }
        vdif[min(n * m - 1, i + cnt * m - 1)]++;
        if (i){
            vdif[i - 1]--;
        }
    }
    FordE(i, n * m - 1, 0){
        if (i < n * m - 1){
            vdif[i] += vdif[i + 1];
        }
    }
    For(i, 0, n * m){
        vans[i] -= vdif[i];
    }
    For(i, 0, n * m){
        cout << vans[i] << ' ';
    }
    cout << endl;
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