#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int pw(int x, int n)
{
        int res = 1;
        while(n > 0){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                n /= 2;
                x = 1ll * x * x % mod;
        }
        return res;
}

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

unordered_map<int, vector<int>> win[33][7];

void build(int l, int r, int A, int lev = 0)
{
        if(l == r){
                win[l][lev][0] = {-1};
                return;
        }
        int m = (l + r) / 2;
        build(l, m, 1ll * A * A % mod, lev + 1);
        build(m + 1, r, 1ll * A * A % mod, lev + 1);

        for(int x = l; x <= m; x++){
                for(int y = m + 1; y <= r; y++){
                        int shit;
                        for(auto z: win[x][lev + 1]){
                                for(auto z2: win[y][lev + 1]){
                                        win[y][lev][(1ll * A * x + z.fi + z2.fi) % mod] = {x, z.fi, z2.fi};
                                        win[x][lev][(1ll * A * y + z.fi + z2.fi) % mod] = {y, z2.fi, z.fi};
                                }
                        }
                }
        }
}

int res[33];

void restore(int l, int r, int X, int H, int lev = 0)
{
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        auto shit = win[X][lev][H];
        int Y = shit[0];
        res[Y] = (1 << lev);

        if(X <= m){
                restore(l, m, X, shit[2], lev + 1);
                restore(m + 1, r, Y, shit[1], lev + 1);
        } else{
                restore(l, m, Y, shit[1], lev + 1);
                restore(m + 1, r, X, shit[2], lev + 1);
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int k, A, H;
        cin >> k >> A >> H;
        H = 1ll * H * pw(A, mod - 2) % mod;

        build(1, 1 << k, A);

        bool good = false;
        for(int i = 1; i <= (1 << k); i++){
                add(H, -i);
                if(win[i][0].find(H) != win[i][0].end()){
                        restore(1, (1 << k), i, H);
                        good = true;
                        break;
                }
                add(H, i);
        }
        if(!good){
                cout << -1 << "\n";
        } else{
                for(int i = 1; i <= (1 << k); i++){
                        cout << res[i] + 1 << " ";
                }
        }
}