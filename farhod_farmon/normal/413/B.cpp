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

        int n, m, k;
        cin >> n >> m >> k;
        vector < vector < int > > a(n, vector < int > (m));
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                }
        }

        vector < int > A(n), B(m);
        for(int i = 0; i < k; i++){
                int x, y;
                cin >> x >> y;

                x -= 1;
                y -= 1;

                A[x] += 1;
                B[y] += 1;
        }

        for(int i = 0; i < n; i++){
                int res = 0;
                for(int j = 0; j < m; j++){
                        res += a[i][j] * B[j];
                }
                res -= A[i];

                cout << res << " ";
        }
}