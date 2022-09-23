#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int nxt[3][2];
long long a[N];
long long d[N][3][2][2];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        long long inf = 1e18;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 0; j < 3; j++){
                        for(int h = 0; h < 2; h++){
                                d[i][j][h][0] = d[i][j][h][1] = -inf;
                        }
                }
        }
        if(n == 1){
                cout << a[1] << "\n";
                return 0;
        }
        d[1][0][0][0] = a[1];
        d[1][1][1][0] = - a[1];

        nxt[0][0] = 1;
        nxt[1][0] = 2;
        nxt[2][0] = 0;
        nxt[0][1] = 2;
        nxt[1][1] = 0;
        nxt[2][1] = 1;

        for(int i = 2; i <= n; i++){
                for(int j = 0; j < 3; j++){
                        for(int last = 0; last < 2; last++){
                                for(int good = 0; good < 2; good++){
                                        for(int cur = 0; cur < 2; cur++){
                                                d[i][nxt[j][cur]][cur][good | (cur == last)] = max(d[i][nxt[j][cur]][cur][good | (cur == last)],
                                                                                                   d[i - 1][j][last][good] + a[i] * (!cur ? 1 : -1));
                                        }
                                }
                        }
                }
        }

        long long res = d[n][0][0][1];
        res = max(res, d[n][0][1][1]);

        cout << res << "\n";
}