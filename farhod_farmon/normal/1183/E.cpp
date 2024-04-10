#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const long long mod = 998244353;

using namespace std;

int n;
string s;
long long SHIT = 1e13;
long long k;
long long d[N][N];
bool shit[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> s;
        s = "#" + s;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                        if(j == 1){
                                d[i][j] = d[i - 1][j] + 1;
                        } else{
                                d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
                        }
                        for(int h = i - 1; h > 0; h--){
                                if(s[i] == s[h]){
                                        if(j == 1){
                                                d[i][j] -= 1;
                                        } else{
                                                d[i][j] -= d[h - 1][j - 1];
                                        }
                                        break;
                                }
                        }
                        if(d[i][j] >= SHIT){
                                shit[j] = true;
                        }
                }
        }
        long long res = 0;
        d[n][0] = 1;
        for(int i = n; i >= 0; i--){
                if(shit[i]){
                        d[n][i] = SHIT;
                }
                res += (n - i) * min(k, d[n][i]);
                k -= min(k, d[n][i]);
        }
        if(k){
                res = -1;
        }
        cout << res << "\n";
}