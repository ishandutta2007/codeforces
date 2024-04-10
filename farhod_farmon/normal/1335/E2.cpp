#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200020;

using namespace std;

int n;
int a[N];
int s[200][N];
vector < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 0; i < 200; i++){
                for(int j = 0; j <= n; j++){
                        s[i][j] = 0;
                }
                v[i].clear();
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= 1;
                s[a[i]][i] += 1;
                v[a[i]].push_back(i);
        }
        for(int i = 0; i < 200; i++){
                for(int j = 1; j <= n; j++){
                        s[i][j] += s[i][j - 1];
                }
        }
        int res = 0;
        for(int i = 0; i < 200; i++){
                for(int j = 0; j < (int)v[i].size() - j - 1; j++){
                        int l = v[i][j], r = v[i][v[i].size() - j - 1];
                        for(int h = 0; h < 200; h++){
                                res = max(res, 2 * (j + 1) + s[h][r - 1] - s[h][l]);
                        }
                }
                res = max(res, (int)v[i].size());
        }
        cout << res << "\n";
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}