#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 14;
const int mod = 998244353;

using namespace std;

long long d[N][2][2];

void solve()
{
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int i = 0; i < N; i++){
                for(int j = 0; j < 2; j++){
                        for(int h = 0; h < 2; h++){
                                d[i][j][h] = 0;
                        }
                }
        }

        d[0][0][0] = 1;
        for(int i = 0; i < n; i++){
                for(int x = 0; x < 2; x++){
                        for(int y = 0; y < 2; y++){
                                for(int c1 = 0; c1 < 10; c1++){
                                        for(int c2 = 0; c2 < 10; c2++){
                                                if((c1 + c2 + x) % 10 != s[i] - '0'){
                                                        continue;
                                                }
                                                d[i + 1][y][(c1 + c2 + x) / 10] += d[i][x][y];
                                        }
                                }
                        }
                }
        }

        long long res = 0;
        res += d[n][0][0];
        cout << res - 2 << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}