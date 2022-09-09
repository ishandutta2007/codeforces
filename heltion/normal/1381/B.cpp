#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000;
int p[maxn * 2 + 1];
bitset<maxn + 1> bs; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= 2 * n; i += 1) cin >> p[i];
        bs.reset();
        bs.set(0);
        int m = 0, s = 0;
        for(int i = 1; i <= 2 * n; i += 1){
            if(p[i] > m){
                m = p[i];
                bs |= bs << s;
                s = 0;
            }
            m = max(m, p[i]);
            s += 1;
        }
        bs |= bs << s;
        cout << (bs.test(n) ? "YES\n" : "NO\n");
    }
    return 0;
}