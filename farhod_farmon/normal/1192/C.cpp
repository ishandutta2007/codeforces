#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

set < string > s[11];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int F(char c)
{
        if('a' <= c && c <= 'z'){
                return c - 'a' + 1;
        } else if('A' <= c && c <= 'Z'){
                return c - 'A' + 27;
        } else{
                return c - '0' + 53;
        }
}

int f[66][66];
int fc[66][66][66];
int col[2][2][2];

int solve(int g)
{
        for(int i = 1; i <= 62; i++){
                for(int j = 1; j <= 62; j++){
                        f[i][j] = 0;
                        for(int h = 1; h <= 62; h++){
                                fc[i][j][h] = 0;
                        }
                }
        }
        for(auto t: s[g]){
                char a = t[0], b = t[t.size() - 1];
                f[F(a)][F(b)] += 1;
        }
        for(int a = 1, b, c, d, gg, gg2; a <= 62; a++){
                for(b = 1; b <= 62; b++){
                        gg = f[a][b];
                        for(c = b; c <= 62; c++){
                                gg2 = 1ll * gg * f[a][c] % mod;
                                for(d = c; d <= 62; d++){
                                        add(fc[b][c][d], 1ll * gg2 * f[a][d] % mod);
                                }
                        }
                }
        }
        for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                        for(int h = 0; h < 2; h++){
                                if(i & j & h) col[i][j][h] = 1;
                                else if((i & j) || (j & h)) col[i][j][h] = 4;
                                else if(i & h) col[i][j][h] = 6;
                                else if(i || j || h) col[i][j][h] = 12;
                                else col[i][j][h] = 24;
                        }
                }
        }
        int res = 0;
        int A, B, C, D;
        for(int a = 1, b, c, d, x; a <= 62; a++){
                for(b = a; b <= 62; b++){
                        for(c = b; c <= 62; c++){
                                for(d = c; d <= 62; d++){
                                        A = fc[b][c][d];
                                        B = fc[a][c][d];
                                        C = fc[a][b][d];
                                        D = fc[a][b][c];
                                        A = 1ll * A * B % mod * C % mod * D % mod;
                                        add(res, 1ll * A * col[a == b][b == c][c == d] % mod);
                                }
                        }
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                string t;
                cin >> t;
                s[t.size()].insert(t);
                reverse(t.begin(), t.end());
                s[t.size()].insert(t);
        }
        int res = 0;
        for(int i = 3; i <= 10; i++){
                add(res, solve(i));
        }
        cout << res << "\n";
}