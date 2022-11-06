#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
constexpr int maxm = 35;
LL f[maxm + 1];
constexpr int mod = 998244353;
void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
unordered_map<LL, int> ump[maxm + 1];
int ans[maxm + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i += 1){
        LL a;
        cin >> a;
        for(int i = maxm; ~i; i -= 1) if((a >> i) & 1) a ^= f[i];
        if(a == 0) k += 1;
        else{
            for(int i = maxm; ~i; i -= 1) if((a >> i) & 1){
                f[i] = a;
                for(int j = i + 1; j <= maxm; j += 1) if((f[j] ^ a) < f[j]) f[j] ^= a;
                break;
            }
        }
    }
    int z = 0;
    ump[0][0] = 1;
    for(int i = 0; i <= maxm; i += 1) if(f[i]){
        for(int j = z; ~j; j -= 1)
            for(auto&[k, w] : ump[j]){
                add(ump[j + 1][k ^ f[i] ^ (1LL << i)], w);
            }
        z += 1;
    }
    for(int i = 0; i <= z; i += 1)
        for(auto&[k, w] : ump[i]) add(ans[i + __builtin_popcountll(k)], w);
    int x = 1;
    for(int i = 0; i < k; i += 1) add(x, x);
    for(int i = 0; i <= m; i += 1) cout << (LL) ans[i] * x % mod << " ";
    return 0;
}