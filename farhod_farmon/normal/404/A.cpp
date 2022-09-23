#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int n;
char c[N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if((i == j || i == n - j + 1) && c[i][j] != c[1][1]){
                cout << "NO\n";
                return 0;
            }
            if(!(i == j || i == n - j + 1) && c[i][j] != c[1][2]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    if(c[1][1] == c[1][2])
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}