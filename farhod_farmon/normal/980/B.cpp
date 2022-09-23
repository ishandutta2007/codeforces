#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
char c[8][N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= 4; i++){
                for(int j = 1; j <= n; j++){
                        c[i][j] = '.';
                }
        }
        if(k % 2 == 0){
                for(int i = 2; i < n && k; i++, k -= 2){
                        c[2][i] = c[3][i] = '#';
                }
        }
        else{
                c[2][n / 2 + 1] = '#'; k--;
                for(int i = 2; i <= n / 2 && k; i++, k -= 2){
                        c[2][n / 2 - i + 2] = c[2][n / 2 + i] = '#';
                }
                for(int i = 2; i < n && k; i++, k -= 2){
                        c[3][i] = c[3][n - i + 1] = '#';
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= 4; i++){
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