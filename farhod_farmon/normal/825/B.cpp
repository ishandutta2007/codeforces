#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n = 10;
char c[22][22];

bool win()
{
        bool won = false;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
                        while(j + f1 <= n && c[i][j + f1] == 'X') f1++;
                        while(i + f2 <= n && c[i + f2][j] == 'X') f2++;
                        while(i + f3 <= n && j + f3 <= n && c[i + f3][j + f3] == 'X') f3++;
                        while(i + f4 <= n && j - f4 >= 1 && c[i + f4][j - f4] == 'X') f4++;
                        won |= (f1 >= 5);
                        won |= (f2 >= 5);
                        won |= (f3 >= 5);
                        won |= (f4 >= 5);
                }
        }
        return won;
}

void solve()
{
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(c[i][j] == '.'){
                                c[i][j] = 'X';
                                if(win()){
                                        cout << "YES" << "\n";
                                        return;
                                }
                                c[i][j] = '.';
                        }
                }
        }
        cout << "NO" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}