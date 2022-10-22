#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5, S = sqrt(N / 5) + 2;

struct fenwick_tree{
    vi bit;
    int n;

    fenwick_tree(int n = 0){
        this->n = n + 1;
        bit.assign(this->n + 1, 0);
    }

    fenwick_tree(vector<int> a) : fenwick_tree(a.size()){
        this->n = a.size() + 1;
        bit.assign(n + 1, 0);
        For(i, 0, a.size()){
            update(i, a[i]);
        }
    }

    int get(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }

    int get(int l, int r){
        return get(r) - get(l - 1);
    }

    void update(int idx, int delta){
        for (; idx <= n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
} bit[S];

int n, m;
int a[N], b[N];
pii queries[N];

int ltim[N];
vpii queriestim[N];

int ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    For(i, 2, S){
        bit[i] = fenwick_tree(i);
    }

    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i] >> b[i];
    }
    ForE(i, 1, m){
        int que, k; cin >> que >> k;
        queries[i] = make_pair(que, k);
        if (que == 1){
            ltim[k] = i;
        }
        else{
            queriestim[k].emplace_back(ltim[k], i - 1);
            ltim[k] = 0;
        }
    }
    ForE(i, 1, n){
        if (ltim[i]){
            queriestim[i].emplace_back(ltim[i], m);
            ltim[i] = 0;
        }
    }
    ForE(i, 1, n){
        if (a[i] + b[i] >= S){
            Fora(&query, queriestim[i]){
                int l = query.fi + a[i];
                while (l <= query.se){
                    ans[l]++;
                    ans[min(l + b[i], query.se + 1)]--;
                    l += a[i] + b[i];
                }
            }
        }
    }
    ForE(i, 1, m){
        ans[i] += ans[i - 1];
    }
    ForE(i, 1, m){
        int que, k; tie(que, k) = queries[i];
        if (que == 1){
            ltim[k] = i;
        }
        if (a[k] + b[k] < S){
            int l = ltim[k] + a[k], r = ltim[k] + a[k] + b[k] - 1;
            l = l % (a[k] + b[k]) + 1; r = r % (a[k] + b[k]) + 1;
            if (l <= r){
                bit[a[k] + b[k]].update(l, que == 1 ? 1 : -1);
                bit[a[k] + b[k]].update(r + 1, que == 1 ? -1 : 1);
            }
            else{
                bit[a[k] + b[k]].update(1, que == 1 ? 1 : -1);
                bit[a[k] + b[k]].update(r + 1, que == 1 ? -1 : 1);
                bit[a[k] + b[k]].update(l, que == 1 ? 1 : -1);
            }
        }
        For(j, 2, S){
            ans[i] += bit[j].get(i % j + 1);
        }
    }
    ForE(i, 1, m){
        cout << ans[i] << endl;
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