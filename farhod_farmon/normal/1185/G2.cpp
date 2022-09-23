#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 51;
const int mod = 1e9 + 7;

using namespace std;

int add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int n;
int T;
int a[N];
int b[N];
int fac[N];
int f[N][N][N][3];
bool used[N][N][N][3];
vector < vector < vector < int > > > d[N * N];

int get(int x, int y, int z, int last)
{
        int &res = f[x][y][z][last];
        if(used[x][y][z][last]){
                return res;
        } else if(x + y + z == 0){
                return 1;
        }
        used[x][y][z][last] = true;
        if(x > 0 && last != 0){
                add(res, get(x - 1, y, z, 0));
        }
        if(y > 0 && last != 1){
                add(res, get(x, y - 1, z, 1));
        }
        if(z > 0 && last != 2){
                add(res, get(x, y, z - 1, 2));
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> T;
        int X = 0, Y = 0, Z = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                b[i] -= 1;
                X += b[i] == 0;
                Y += b[i] == 1;
                Z += b[i] == 2;
        }
        for(int i = 0; i <= T; i++){
                d[i].resize(X + 1);
                for(int j = 0; j <= X; j++){
                        d[i][j].resize(Y + 1);
                        for(int h = 0; h <= Y; h++){
                                for(int z = 0; z <= Z; z++){
                                        d[i][j][h].push_back(0);
                                }
                        }
                }
        }
        d[0][0][0][0] = 1;
        fac[0] = 1;
        for(int i = 1; i <= n; i++){
                fac[i] = 1ll * fac[i - 1] * i % mod;
                for(int j = T - a[i]; j >= 0; j--){
                        for(int x = 0; x <= X; x++){
                                for(int y = 0; y <= Y; y++){
                                        for(int z = 0; z <= Z; z++){
                                                if(!d[j][x][y][z]){
                                                        continue;
                                                }
                                                add(d[j + a[i]][x + (b[i] == 0)][y + (b[i] == 1)][z + (b[i] == 2)], d[j][x][y][z]);
                                        }
                                }
                        }
                }
        }
        int res = 0;
        for(int x = 0; x <= X; x++){
                for(int y = 0; y <= Y; y++){
                        for(int z = 0; z <= Z; z++){
                                int cnt = 0;
                                if(x > 0){
                                        add(cnt, get(x - 1, y, z, 0));
                                }
                                if(y > 0){
                                        add(cnt, get(x, y - 1, z, 1));
                                }
                                if(z > 0){
                                        add(cnt, get(x, y, z - 1, 2));
                                }
                                cnt = 1ll * cnt * fac[x] % mod;
                                cnt = 1ll * cnt * fac[y] % mod;
                                cnt = 1ll * cnt * fac[z] % mod;
                                add(res, d[T][x][y][z] * 1ll * cnt % mod);
                        }
                }
        }
        cout << res << "\n";
}