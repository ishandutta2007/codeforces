#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxm = 10000000 + 1;
int np[maxm], p[maxm], f[maxm], pn;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1] = 1;
    for(int i = 2; i < maxm; i += 1){
        if(not np[i]){
            f[i] = i;
            p[pn ++] = i;
        }
        for(int j = 0; j < pn; j += 1){
            int k = i * p[j];
            if(k >= maxm) break;
            np[k] = 1;
            if(f[i] % p[j]) f[k] = f[i] * p[j];
            else f[k] = f[i] / p[j];
            if(i % p[j] == 0) break;
        }
    }
    int T;
    for(cin >> T; T; T -= 1){
        int n, k, ans = 1;
        cin >> n >> k;
        set<int> s;
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            if(s.count(f[a])){
                ans += 1;
                s.clear();
            }
            s.insert(f[a]);
        }
        cout << ans << "\n";
    }
    return 0;
}