#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 550;

using namespace std;

int n;
lli a[N][N];
int x;
int y;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    lli need = 0;
    lli sum = 0;
    for(int i = 1; i <= n; i++){
        if(x == i)
            continue;
        for(int j = 1; j <= n; j++){
            need = need + a[i][j];
            sum = sum + a[x][j];
        }
        break;
    }
    a[x][y] = need - sum;
    if(a[x][y] <= 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        lli s1 = 0;
        lli s2 = 0;
        for(int j = 1; j <= n; j++){
            s1 = s1 + a[i][j];
            s2 = s2 + a[j][i];
        }
        if(s1 != need || s2 != need){
            cout << -1 << endl;
            return 0;
        }
    }
    lli s1 = 0;
    lli s2 = 0;
    for(int i = 1; i <= n; i++){
        s1 += a[i][i];
        s2 += a[i][n - i + 1];
    }
    if(s1 != need || s2 != need){
        cout << -1 << endl;
        return 0;
    }
    cout << a[x][y] << endl;
    return 0;
}