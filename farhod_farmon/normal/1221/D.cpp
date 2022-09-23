#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                int n;
                cin >> n;
                vector < int > a(n + 1), b(n + 1);
                vector < vector < long long > > d(n + 1);
                d[0] = {0, 0, 0, 0};
                a[0] = -6;
                for(int i = 1; i <= n; i++){
                        cin >> a[i] >> b[i];

                        long long inf = 2e18;
                        d[i] = {inf, inf, inf, inf};

                        for(int j = 0; j < 4; j++){
                                for(int h = 0; h < 4; h++){
                                        if(a[i - 1] + j == a[i] + h){
                                                continue;
                                        }
                                        d[i][h] = min(d[i][h], d[i - 1][j] + 1ll * h * b[i]);
                                }
                        }
                }

                long long res = d[n][0];
                res = min(res, d[n][1]);
                res = min(res, d[n][2]);
                res = min(res, d[n][3]);

                cout << res << "\n";
        }
}