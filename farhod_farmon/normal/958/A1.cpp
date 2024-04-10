#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 111;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
char a[N][N];
char b[N][N];
char c[N][N];

bool check()
{
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(a[i][j] != b[i][j]){
                                return false;
                        }
                }
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> b[i][j];
                }
        }
        for(int i = 0; i < 2; i++){
                for(int j = 0; j < 4; j++){
                        if(check()){
                                cout << "Yes" << "\n";
                                return;
                        }
                        for(int i = 1; i <= n; i++){
                                for(int j = 1; j <= n; j++){
                                        c[i][j] = a[n - j + 1][i];
                                }
                        }
                        for(int i = 1; i <= n; i++){
                                for(int j = 1; j <= n; j++){
                                        a[i][j] = c[i][j];
                                }
                        }
                }
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= n / 2; j++){
                                swap(a[i][j], a[i][n - j + 1]);
                        }
                }
        }
        cout << "No" << "\n";
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