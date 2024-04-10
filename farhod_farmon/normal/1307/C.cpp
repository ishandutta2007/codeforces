#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

string s;
int c[200];
long long f[200][200];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> s;
        for(int i = 0; i < s.size(); i++){
                char x = s[i];
                c[x] += 1;
                for(char j = 'a'; j <= 'z'; j++){
                        if(j == x){
                                continue;
                        }
                        f[j][x] += c[j];
                }
        }
        long long res = 0;
        for(char i = 'a'; i <= 'z'; i++ ){
                for(char j = 'a'; j <= 'z'; j++){
                        res = max(res, f[i][j]);
                }
                res = max(res, 1ll * c[i] * (c[i] - 1) / 2);
                res = max(res, 1ll * c[i]);
        }
        cout << res << "\n";
}