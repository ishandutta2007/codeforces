#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a;
int b;
bool c[N][N];

void solve()
{
        cin >> n >> a >> b;
        if(min(a, b) > 1){
                cout << "NO" << "\n";
                return;
        }
        if(n == 1){
                cout << "YES" << "\n";
                cout << 0 << "\n";
                return;
        }
        if(max(a, b) == 1 && n < 4){
                cout << "NO" << "\n";
                return;
        }
        else if(a == 1){
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= n; j++){
                                c[i][j] = 1;
                        }
                        c[i][i] = 0;
                }
                int col = n - b;
                for(int i = 1; i <= col; i++){
                        c[i][i + 1] = c[i + 1][i] = 0;
                }
        }
        else{
                int col = n - a;
                for(int i = 1; i <= col; i++){
                        c[i][i + 1] = c[i + 1][i] = 1;
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cout << c[i][j];
                }
                cout << "\n";
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