#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 505;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
long long d[N][N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i < k; i++){
                d[0][i] = -1e18;
        }
        for(int i = 1; i <= n; i++){
                long long a, b;
                cin >> a >> b;
                for(int j = 0; j < k; j++){
                        d[i][j] = d[i - 1][j];
                }
                for(int x = 0; x < k; x++){
                        long long y = (a + b - x) % k;
                        if(x > a || y > b){
                                continue;
                        }
                        long long cost, shit;
                        shit = a + b - x;
                        for(int h = 0, nh; h < k; h++){
                                nh = h + x;
                                cost = shit;
                                if(nh >= k){
                                        nh -= k;
                                        cost += k;
                                }
                                d[i][nh] = max(d[i][nh], d[i - 1][h] + cost);
                        }
                }
        }
        long long res = 0;
        for(int i = 0; i < k; i++){
                res = max(res, d[n][i] / k);
        }
        cout << res << "\n";
}