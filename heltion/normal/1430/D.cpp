#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        string s;
        cin >> n >> s;
        int qh = 0, qt = 0, L = -1;
        for(char c : s){
            if(c != L){
                L = c;
                q[qt ++] = 0;
            }
            q[qt - 1] += 1;
        }
        int ans = 0, x = 0;
        while(qh < qt){
            x = max(x, qh);
            while(x < qt and q[x] == 1) x += 1;
            if(x < qt) q[x] -= 1;
            else qh += 1;
            qh += 1;
            ans += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}