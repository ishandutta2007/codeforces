#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 6;
const int mod = 1e9 + 7;

using namespace std;

int n;
string s;

void solve()
{
        cin >> n >> s;
        int len = s.size();
        int x = 0;
        for(int i = 1; i <= n; i++){
                x = (s[i - 1] - '0') % mod - 1;
                int c = len - i;
                if(c < 0){
                        c += mod;
                }
                len += 1ll * c * x % mod;
                if(len >= mod){
                        len -= mod;
                }
                while(x > 0 && s.size() <= n){
                        int t = s.size() - c;
                        for(int j = 0; j < c; j++){
                                s += s[t + j];
                        }
                        x -= 1;
                }
        }
        cout << len << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}