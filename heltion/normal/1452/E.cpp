#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000 + 2;
int kx[maxn][maxn], b[maxn][maxn], f[maxn];
void add(int a[][maxn], int x, int y1, int y2, int v){
    a[x][y1] += v;
    a[x][y2 + 1] -= v;
}
struct SHIT{
    int k, b, x, y;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1, l, r; i <= m; i += 1){
        cin >> l >> r;
        for(int j = 1; j <= n; j += 1){
            int L = max(l, j), R = min(r, j + k - 1);
            f[j] = max(R - L + 1, 0);
        }
        vector<SHIT> shits;
        for(int i = 1; i <= n; i += 1){
            if(i == m) shits.push_back({0, f[i], i, i});
            else{
                int j = i;
                while(j + 1 <= n and f[j + 1] - f[j] == f[i + 1] - f[i]) j += 1;
                shits.push_back({f[i + 1] - f[i], f[i] - (f[i + 1] - f[i]) * i, i, j});
                i = j;
            }
        }
        for(int i = 1; i <= n; i += 1){
            for(auto s : shits){
                if(s.k == 0)
                    add(b, i, s.x, s.y, max(s.b, f[i]));
                else if(s.k == 1){
                    if(s.x + s.b >= f[i]){
                        add(kx, i, s.x, s.y, 1);
                        add(b, i, s.x, s.y, s.b);
                    }
                    else if(s.y + s.b <= f[i])
                        add(b, i, s.x, s.y, f[i]);
                    else{
                        int m = f[i] - s.b;
                        add(b, i, s.x, m, f[i]);
                        add(kx, i, m + 1, s.y, 1);
                        add(b, i, m + 1, s.y, s.b);
                    }
                }
                else{
                    if(-s.y + s.b >= f[i]){
                        add(kx, i, s.x, s.y, -1);
                        add(b, i, s.x, s.y, s.b);
                    }
                    else if(-s.x + s.b <= f[i])
                        add(b, i, s.x, s.y, f[i]);
                    else{
                        int m = s.b - f[i];
                        add(b, i, m, s.y, f[i]);
                        add(kx, i, s.x, m - 1, -1);
                        add(b, i, s.x, m - 1, s.b);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i += 1) for(int j = 1; j <= n; j += 1){
        kx[i][j] += kx[i][j - 1];
        b[i][j] += b[i][j - 1];
        ans = max(ans, kx[i][j] * j + b[i][j]);
    }
    cout << ans;
    return 0;
}