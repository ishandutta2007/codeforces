#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int f[N][N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                f[i][i] = x;
        }
        for(int i = n; i >= 1; i--){
                for(int j = i + 1; j <= n; j++){
                        f[i][j] = f[i + 1][j] ^ f[i][j - 1];
                }
        }
        for(int i = n; i >= 1; i--){
                for(int j = i + 1; j <= n; j++){
                        f[i][j] = max(f[i][j], f[i + 1][j]);
                        f[i][j] = max(f[i][j], f[i][j - 1]);
                }
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                cout << f[l][r] << "\n";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}