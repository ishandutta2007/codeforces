#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int c[N];
int d[N][7][7];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x] += 1;
        }
        if(m == 1){
                cout << c[1] / 3 << "\n";
                return 0;
        }
        if(m == 2){
                cout << c[1] / 3 + c[2] / 3 << "\n";
                return 0;
        }
        int r1, r2, r3;
        for(int i = 1; i + 2 <= m; i++){
                for(int x = 0; x < 7; x++){
                        for(int y = 0; y < 7; y++){
                                for(int z = 0; z < 3; z++){
                                        r1 = c[i] - x - z;
                                        r2 = c[i + 1] - y - z;
                                        r3 = c[i + 2] - z;
                                        if(r1 < 0 || r2 < 0 || r3 < 0){
                                                continue;
                                        }
                                        d[i + 1][y + z][z] = max(d[i + 1][y + z][z], d[i][x][y] + z + r1 / 3);
                                }
                        }
                }
        }
        int res = 0;
        for(int x = 0; x < 7; x++){
                for(int y = 0; y < 7; y++){
                        r1 = c[m - 1] - x;
                        r2 = c[m] - y;
                        if(r1 < 0 || r2 < 0){
                                continue;
                        }
                        res = max(res, d[m - 1][x][y] + r1 / 3 + r2 / 3);
                }
        }
        cout << res << "\n";
}