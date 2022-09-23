#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int k;
int d[19][1 << 10][2];
int f[19][1 << 10][2];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int get(string s)
{
        if(s.size() == 0){
                return 0;
        }
        if(s.size() == 1 && s[0] == 0){
                return 0;
        }
        for(int i = 0; i < 19; i++){
                for(int j = 0; j < (1 << 10); j++){
                        f[i][j][0] = 0;
                        f[i][j][1] = 0;
                        d[i][j][0] = 0;
                        d[i][j][1] = 0;
                }
        }
        for(int i = 1; i < s[0]; i++){
                d[0][1 << i][0] = 1;
                f[0][1 << i][0] = i;
        }
        int n = s.size();
        d[0][1 << s[0]][1] = 1;
        f[0][1 << s[0]][1] = s[0];
        for(int i = 1; i < n; i++){
                for(int j = 0; j < (1 << 10); j++){
                        for(int h = 0; h < 10; h++){
                                int nj = j | (1 << h);
                                add(d[i][nj][0], d[i - 1][j][0]);
                                add(f[i][nj][0], (1ll * f[i - 1][j][0] * 10 % mod + 1ll * d[i - 1][j][0] * h % mod) % mod);
                                if(h < s[i]){
                                        add(d[i][nj][0], d[i - 1][j][1]);
                                        add(f[i][nj][0], (1ll * f[i - 1][j][1] * 10 % mod + h * d[i - 1][j][1]) % mod);
                                }
                                if(h == s[i]){
                                        add(d[i][nj][1], d[i - 1][j][1]);
                                        add(f[i][nj][1], (1ll * f[i - 1][j][1] * 10 % mod + h * d[i - 1][j][1]) % mod);
                                }
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i < (1 << 10); i++){
                if(__builtin_popcount(i) <= k){
                        add(ans, f[n - 1][i][0]);
                        add(ans, f[n - 1][i][1]);
                }
        }
        return ans;
}

int fe(string s)
{
        int ans = get(s);
        string t = "";
        t += char(9);
        while(t.size() < s.size()){
                add(ans, get(t));
                t += char(9);
        }
        return ans;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        long long x, y;
        cin >> x >> y >> k;
        string s = "", t = "";
        x--;
        while(x){
                s += x % 10;
                x /= 10;
        }
        reverse(s.begin(), s.end());
        while(y){
                t += y % 10;
                y /= 10;
        }
        reverse(t.begin(), t.end());
        cout << (fe(t) - fe(s) + mod) % mod << "\n";
}