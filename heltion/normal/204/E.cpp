#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
namespace suffix_array{
    int s[maxn], p[maxn], c[maxn], cnt[maxn], pn[maxn], cn[maxn];
    int rk[maxn], hi[maxn], rmq[maxn][17], Log[maxn];
    void init(int n){
        for(int i = 0; i < n; i += 1) p[i] = i;
        sort(p, p + n, [&](int x, int y){
            return s[x] < s[y];
        });
        int k = 1;
        c[p[0]] = 0;
        for(int i = 1; i < n; i += 1) {
            if(s[p[i]] != s[p[i - 1]]) k += 1;
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

        for(int i = 0; i < 17; i += 1)
            for(int j = 1; j + (1 << i) <= n; j += 1)
                rmq[j][i] = i ? min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]) : hi[j];
        for(int i = 2; i <= n; i += 1) Log[i] = Log[i >> 1] + 1;
    }
};
using namespace suffix_array;
int L[maxn], R[maxn], id[maxn], nxt[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, sn = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1){
        string t;
        cin >> t;
        L[i] = sn;
        for(char c : t) s[sn ++] = c - 'a';
        R[i] = sn;
        for(int j = L[i]; j < R[i]; j += 1) id[j] = i;
        s[sn ++] = i + 25;
    }
    init(sn);
    map<int, int> mp;
    for(int i = 0, j = 0; i < sn; i += 1){
        while(j < sn and mp.size() < k){
            mp[id[p[j]]] += 1;
            j += 1;
        }
        if(mp.size() == k) nxt[i] = j - 1;
        else nxt[i] = sn;
        if(not(mp[id[p[i]]] -= 1)) mp.erase(id[p[i]]);
    }
    auto check = [&](int x, int y)->bool{
        int L = rk[x], R = rk[x];
        for(int i = 16; ~i; i -= 1) if(L >= (1 << i) and rmq[L - (1 << i) + 1][i] >= y - x + 1) L -= 1 << i;
        for(int i = 16; ~i; i -= 1) if(R + (1 << i) <= sn and rmq[R + 1][i] >= y - x + 1) R += 1 << i;
        return nxt[L] <= R;
    }; 
    for(int i = 1; i <= n; i += 1){
        LL ans = 0;
        for(int j = L[i], k = L[i]; j < R[i]; j += 1){
            k = max(j, k);
            if(not check(j, k)) continue;
            while(k + 1 < R[i] and check(j, k + 1)) k += 1;
            ans += k - j + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}