#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 11;
const int mod = 998244353;

int n;
int d;
vector < int > v[N];
long double f[N][N];
pair < int, int > p[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> d;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x % 10].push_back(x);
        }
        for(int i = 0; i < 10; i++){
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
        }
        if(d == 0){
                int all = 1;
                for(int i = 0; i < 10; i++){
                        for(int x: v[i]){
                                all = all * x % 10;
                        }
                }
                if(all){
                        cout << -1 << "\n";
                        return 0;
                }
                cout << n << "\n";
                for(int i = 0; i < 10; i++){
                        for(int x: v[i]){
                                cout << x << " ";
                        }
                }
                return 0;
        }

        for(int i = 0; i < 10; i++){
                f[0][i] = -1;
        }
        f[0][1] = 0;
        for(int i = 1; i < 10; i++){
                for(int j = 0; j < 10; j++){
                        f[i][j] = f[i - 1][j];
                        p[i][j] = {0, j};
                }
                for(int j = 0; j < 10; j++){
                        if(f[i - 1][j] == -1){
                                continue;
                        }

                        long double sum = 0;
                        int h = j;
                        for(int x = 0; x < v[i].size(); x++){
                                h = h * i % 10;
                                sum += log(v[i][x]);
                                if(f[i - 1][j] + sum > f[i][h]){
                                        f[i][h] = f[i - 1][j] + sum;
                                        p[i][h] = {x + 1, j};
                                }
                        }
                }
        }
        if(f[9][d] == -1){
                cout << -1 << "\n";
                return 0;
        }
        vector < int > res;
        for(int i = 9; i > 0; i--){
                auto shit = p[i][d];
                for(int j = 0; j < shit.fi; j++){
                        res.push_back(v[i][j]);
                }
                d = shit.se;
        }
        if(res.empty()){
                cout << -1 << "\n";
                return 0;
        }
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}