#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
char a[N][N];
char b[N][N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        b[i][j] = '.';
                }
        }
        for(int i = 2; i < n; i++){
                for(int j = 2; j < m; j++){
                        bool can = true;
                        for(int dx = -1; dx <= 1; dx++){
                                for(int dy = -1; dy <= 1; dy++){
                                        if(dx == 0 && dy == 0){
                                                continue;
                                        }
                                        can &= a[i + dx][j + dy] == '#';
                                }
                        }
                        if(can){
                                for(int dx = -1; dx <= 1; dx++){
                                        for(int dy = -1; dy <= 1; dy++){
                                                if(dx == 0 && dy == 0){
                                                        continue;
                                                }
                                                b[i + dx][j + dy] = '#';
                                        }
                                }
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(a[i][j] != b[i][j]){
                                cout << "NO" << "\n";
                                return;
                        }
                }
        }
        cout << "YES" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}