#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 255;

using namespace std;

int n, m;
int a[N][N];
vector < int > A, B;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        A.push_back(0);
        B.push_back(0);
        for(int i = 1; i <= n; i++){
                int mx = 0;
                for(int j = 1; j <= m; j++) mx = max(mx, a[i][j]);
                A.push_back(mx);
        }
        for(int j = 1; j <= m; j++){
                int mx = 0;
                for(int i = 1; i <= n; i++) mx = max(mx, a[i][j]);
                B.push_back(mx);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        a[i][j] = 0;
                }
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = n, j = m, sh = 0;
        vector < pair < int, int > > em;
        for(int x = n * m; x >= 1; x--){
                if(A[i] == x && B[j] == x){
                        a[i][j] = x;
                        for(int h = i + 1; h <= n; h++) em.push_back({h, j});
                        for(int h = j + 1; h <= m; h++) em.push_back({i, h});
                        i -= 1;
                        j -= 1;
                } else if(A[i] == x){
                        a[i][j + 1] = x;
                        for(int h = j + 2; h <= m; h++) em.push_back({i, h});
                        i -= 1;
                } else if(B[j] == x){
                        a[i + 1][j] = x;
                        for(int h = i + 2; h <= n; h++) em.push_back({h, j});
                        j -= 1;

                } else{
                        auto p = em[sh++];
                        a[p.fi][p.se] = x;
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cout << a[i][j] << ' ';
                }
                cout << '\n';
        }
}