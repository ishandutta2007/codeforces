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

const int N = 1e2 + 5;

int n;
int a[N];

ll f[N], pf[N];
priority_queue <pii> pq;
int b[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
f[1] = f[2] = 1;
ForE(i, 3, 60){
    f[i] = f[i - 1] + f[i - 2];
}
ForE(i, 1, 60){
    pf[i] = pf[i - 1] + f[i];
}
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll sum = accumulate(a + 1, a + n + 1, 0ll);
    int k = 0;
    while (pf[k + 1] <= sum){
        k++;
    }
    if (pf[k] != sum){
        cout << "NO" << endl;
        continue;
    }
    while (!pq.empty()){
        pq.pop();
    }
    ForE(i, 1, n){
        pq.emplace(a[i], i);
    }
    bool ck = 1; int pb = -1;
    FordE(i, k, 1){
        int idx; tie(ignore, idx) = pq.top(); pq.pop();
        if (a[idx] < f[i]){
            ck = 0;
            break;
        }
        if (idx != pb){
            b[i] = idx; a[idx] -= f[i]; pq.emplace(a[idx], idx); pb = idx;
            continue;
        }
        if (pq.empty()){
            ck = 0;
            break;
        }
        int idx2; tie(ignore, idx2) = pq.top(); pq.pop();
        if (a[idx2] < f[i]){
            ck = 0;
            break;
        }
        if (idx2 != pb){
            b[i] = idx2; a[idx2] -= f[i]; pq.emplace(a[idx2], idx2); pb = idx2;
            pq.emplace(a[idx], idx);
            continue;
        }
        ck = 0;
        break;
    }
    if (!ck){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
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