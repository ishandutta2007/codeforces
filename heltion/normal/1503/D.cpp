#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 400000 + 1;
int a[maxn], b[maxn], p[maxn], vis[maxn];
void no(){
    cout << -1;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i] >> b[i];
        p[a[i]] = i;
        p[b[i]] = i;
    }
    vector<tuple<int, int, int>> w;
    int ans = 0;
    int L = 1, R = 2 * n;
    while(L <= R){
        int tL = L + 1, tR = R, x = 0, y = 0;
        while(true){
            int ch = 0;
            for(;L < tL; L += 1) if(not vis[L]){
                int pL = p[L];
                int dL = a[pL] ^ b[pL] ^ L;
                if(dL > tR) no();
                if(dL < tL) no();
                x += a[pL] == L;
                y += b[pL] == L;
                vis[a[pL]] = vis[b[pL]] = 1;
                tR = dL;
                ch = 1;
            }
            for(;R > tR; R -= 1) if(not vis[R]){
                int pR = p[R];
                int dR = a[pR] ^ b[pR] ^ R;
                if(dR < tL) no();
                if(dR > tR) no();
                x += a[pR] == R;
                y += b[pR] == R;
                vis[a[pR]] = vis[b[pR]] = 1;
                tL = dR;
                ch = 1;
            }
            if(not ch) break;
        }
        ans += min(x, y);
    }
    cout << ans;
    return 0;
}