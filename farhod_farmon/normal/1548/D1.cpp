#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 6000;

using namespace std;

int n;
int d[N][N];
int a[N], b[N];
int c[2][2];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i] >> b[i];
                a[i] /= 2;
                b[i] /= 2;
        }

        for(int i = 0; i < n; i++){
                a[i] %= 2;
                b[i] %= 2;
                c[a[i]][b[i]] += 1;
        }
        vector<pair<int, int>> v;
        for(int i = 0; i < 2; i++){
                v.push_back({i, 0});
                v.push_back({i, 1});
        }

        long long res = 0;

        for(int i = 0; i < v.size(); i++){
                for(int j = i; j < v.size(); j++){
                        for(int h = j; h < v.size(); h++){
                                int s = 0;
                                s ^= (v[i].fi ^ v[j].fi) | (v[i].se ^ v[j].se);
                                s ^= (v[i].fi ^ v[h].fi) | (v[i].se ^ v[h].se);
                                s ^= (v[h].fi ^ v[j].fi) | (v[h].se ^ v[j].se);
                                long long a = c[v[i].fi][v[i].se];
                                long long b = c[v[j].fi][v[j].se];
                                long long c = ::c[v[h].fi][v[h].se];
                                if(s == 0){
                                        if(i == j && j == h){
                                                res += a * (a - 1) * (a - 2) / 6;
                                        } else if(i == j){
                                                res += a * (a - 1) / 2 * c;
                                        } else if(j == h){
                                                res += a * b * (b - 1) / 2;
                                        } else{
                                                res += a * b * c;
                                        }
                                }
                        }
                }
        }

        cout << res << "\n";
}