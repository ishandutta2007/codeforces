#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 101;

bitset < N * N > d[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        d[1][1][0] = 1;
        for(int i = 1; i < N; i++){
                for(int j = (i == 1 ? 2 : 1); j < N; j++){
                        d[i][j] |= (d[i - 1][j] << j);
                        d[i][j] |= (d[i][j - 1] << i);
                }
        }
        int t;
        cin >> t;
        while(t--){
                int a, b, c;
                cin >> a >> b >> c;
                cout << (d[a][b][c] ? "YES" : "NO") << "\n";
        }
}