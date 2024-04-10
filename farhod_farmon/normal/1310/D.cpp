#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 128;

using namespace std;

int n;
int k;
int b[N];
int a[N][N];
int d[N];
int f[N];
int inf = (1e9) + (7e8);

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        vector < int > ord;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cin >> a[i][j];
                }
                ord.push_back(i);
        }
        int res = inf;
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        while(1.0 * clock() / CLOCKS_PER_SEC < 2.8){
                shuffle(ord.begin(), ord.end(), rng);
                for(int i = 0; i < n; i++){
                        b[ord[i]] = (i & 1);
                }
                for(int j = 0; j < n; j++){
                        d[j] = f[j] = inf;
                }
                d[0] = 0;
                for(int i = 0; i < k; i++){
                        for(int j = 0; j < n; j++){
                                for(int h = 0; h < n; h++){
                                        if(b[j] == b[h]){
                                                continue;
                                        } else if(f[h] > d[j] + a[j][h]){
                                                f[h] = d[j] + a[j][h];
                                        }
                                }
                        }
                        for(int j = 0; j < n; j++){
                                d[j] = f[j];
                                f[j] = inf;
                        }
                }
                res = min(res, d[0]);
        }
        cout << res << "\n";
}