#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 400000 + 1;
namespace suffix_array{
    int s[maxn], p[maxn], c[maxn], cnt[maxn], pn[maxn], cn[maxn];
    int rk[maxn], hi[maxn];
    void init(int n){
        int k = 1;
        for(int i = 0; i < n; i += 1) cnt[s[i]] += 1;
        for(int i = 1; i < maxn; i += 1) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i += 1) p[cnt[s[i]] -= 1] = i;
        c[p[0]] = 0;
        for (int i = 1; i < n; i += 1) {
            if (s[p[i]] != s[p[i - 1]]) k += 1;
            c[p[i]] = k - 1;
        }
        for(int h = 0; (1 << h) < n; h += 1){
            for(int i = 0; i < n; i += 1){
                pn[i] = p[i] - (1 << h);
                if(pn[i] < 0) pn[i] += n;
            }
            for(int i = 0; i < k; i += 1) cnt[i] = 0;
            for(int i = 0; i < n; i += 1) cnt[c[pn[i]]]++;
            for(int i = 1; i < k; i += 1) cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; i -= 1) p[cnt[c[pn[i]]] -= 1] = pn[i];
            cn[p[0]] = 0;
            k = 1;
            for(int i = 1; i < n; i += 1) {
                if(c[p[i]] != c[p[i - 1]] or c[(p[i] + (1 << h)) % n] != c[(p[i - 1] + (1 << h)) % n]) k += 1;
                cn[p[i]] = k - 1;
            }
            for(int i = 0; i < n; i += 1) swap(c[i], cn[i]);
        }

        for(int i = 0; i < n; i += 1) rk[p[i]] = i;
        for(int i = 0, j, k = 0; i < n; i += 1) if(rk[i]){
            for(k ? k -- : 0, j = p[rk[i] - 1]; s[i + k] == s[j + k]; k += 1);
            hi[rk[i]] = k;
        }
    }
};
using namespace suffix_array;
int L[maxn], R[maxn], X[maxn], Y[maxn], per[maxn], ss[maxn];
constexpr int maxm = 500000 + 1;
vector<int> Q[maxm];
int l[maxm], r[maxm], k[maxm], ans[maxm];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, sn = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1){
        string t;
        cin >> t;
        L[i] = sn;
        for(char c : t) s[sn ++] = c - 'a' + 1;
        R[i] = sn;
        s[sn ++] = i + 26;
    }
    s[sn ++] = 0;
    init(sn);
    for(int i = 1; i <= n; i += 1)
        per[rk[L[i]]] = i;
    vector<pair<int, int>> vx;
    for(int i = 1; i < sn; i += 1){
        while(not vx.empty() and hi[i] <= vx.back().first) vx.pop_back();
        vx.push_back({hi[i], i});
        if(per[i]){
            auto it = prev(lower_bound(vx.begin(), vx.end(), make_pair(R[per[i]] - L[per[i]], 0)));
            X[per[i]] = it->second;
        }
    }
    vector<pair<int, int>> vy;
    for(int i = sn - 1; i >= 1; i -= 1){
        if(per[i]){
            auto it = prev(lower_bound(vy.begin(), vy.end(), make_pair(R[per[i]] - L[per[i]], 0)));
            Y[per[i]] = it->second;
        }
        while(not vy.empty() and hi[i] <= vy.back().first) vy.pop_back();
        vy.push_back({hi[i], i - 1});
    }
    for(int i = 1; i <= m; i += 1){
        cin >> l[i] >> r[i] >> k[i];
        Q[l[i] - 1].push_back(i);
        Q[r[i]].push_back(i);
    }
    auto add = [&](int u){
        for(u += 1; u <= maxn; u += u & -u) ss[u] += 1;
    };
    function<int(int)> sum = [&](int u){
        int res = 0;
        for(u += 1; u; u -= u & -u) res += ss[u];
        return res;
    };
    for(int i = 1; i <= n; i += 1){
        for(int j = L[i]; j < R[i]; j += 1) add(rk[j]);
        for(int j : Q[i]) if(i + 1 == l[j]) ans[j] -= sum(Y[k[j]]) - sum(X[k[j]] - 1);
        for(int j : Q[i]) if(i == r[j]) ans[j] += sum(Y[k[j]]) - sum(X[k[j]] - 1);
    }
    for(int i = 1; i <= m; i += 1) cout << ans[i] << "\n";
    return 0;
}