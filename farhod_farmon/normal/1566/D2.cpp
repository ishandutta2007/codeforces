#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

using namespace std;

int n;
int m;
int b[N][N];

void solve()
{
        cin >> n >> m;
        map<int, vector<int>> v;
        for(int i = 0, x; i < n * m; i++){
                cin >> x;
                v[x].push_back(i);
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        b[i][j] = 0;
                }
        }

        int cur = 0;
        for(auto p: v){
                sort(p.se.begin(), p.se.end());
                int l = cur, r = cur + p.se.size() - 1;
                if(l / m == r / m){
                        for(int i = 0; i < p.se.size(); i++){
                                b[l / m][l % m + i] = p.se[p.se.size() - i - 1];
                        }
                        cur += p.se.size();
                        continue;
                }

                int A = m - l % m;
                int B = r % m + 1;

                for(int i = 0; i < A; i++){
                        b[l / m][l % m + i] = p.se[A - i - 1];
                }
                for(int i = 0; i < B; i++){
                        b[r / m][i] = p.se[p.se.size() - i - 1];
                }
                cur += p.se.size();
        }

        int res = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        for(int h = j + 1; h < m; h++){
                                res += (b[i][j] < b[i][h]);
                        }
                }
        }

        cout << res << "\n";
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