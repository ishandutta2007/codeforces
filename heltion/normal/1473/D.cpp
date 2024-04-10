#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
char s[maxn];
int sum[maxn], pmi[maxn], smi[maxn], pma[maxn], sma[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, q;
        cin >> n >> q >> s;
        for(int i = 0; i < n; i += 1) sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1);
        for(int i = 0; i <= n; i += 1){
            pmi[i] = pma[i] = sum[i];
            if(i){
                pmi[i] = min(pmi[i - 1], pmi[i]);
                pma[i] = max(pma[i - 1], pma[i]);
            }
        }
        for(int i = n; i >= 0; i -= 1){
            smi[i] = sma[i] = sum[i];
            if(i < n){
                smi[i] = min(smi[i + 1], smi[i]);
                sma[i] = max(sma[i + 1], sma[i]);
            }
        }
        for(int l, r; q; q -= 1){
            cin >> l >> r;
            int mi = min(pmi[l - 1], smi[r] - sum[r] + sum[l - 1]);
            int ma = max(pma[l - 1], sma[r] - sum[r] + sum[l - 1]);
            //cout << mi << " "<< ma << "\n";
            cout << ma - mi + 1 << '\n';
        }
    }
    return 0;
}