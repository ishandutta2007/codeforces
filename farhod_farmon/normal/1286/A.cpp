#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;

using namespace std;

int n;
int a[N];
int d[N][N][2];
bool dead[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                        d[i][j][0] = 2e9;
                        d[i][j][1] = 2e9;
                }
        }
        d[0][0][0] = 0;
        d[0][0][1] = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                dead[a[i]] = true;

                int x = a[i] % 2, y = x;
                if(!a[i]){
                        y = x ^ 1;
                }
                for(int j: {x, y}){
                        for(int h = 0; h <= n; h++){
                                int nh = h;
                                if(!j && !a[i]){
                                        nh += 1;
                                }
                                d[i][nh][j] = min(d[i][nh][j], d[i - 1][h][0] + (j != 0));
                                d[i][nh][j] = min(d[i][nh][j], d[i - 1][h][1] + (j != 1));
                        }
                }
        }
        int have = 0;
        for(int i = 1; i <= n; i++){
                if(!dead[i]){
                        have += (i % 2) == 0;
                }
        }
        cout << min(d[n][have][0], d[n][have][1]) << "\n";
}