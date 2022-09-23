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

using namespace std;

int n, c[50][50];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n;
    int x = 1;
    for(int i = 1; i <= n; i++){
        if(i == n / 2 + 1)
            continue;
        c[n / 2 + 1][i] = x;
        x += 2;
        c[i][n / 2 + 1] = x;
        x += 2;
    }
    c[n / 2 + 1][n / 2 + 1] = x;
    x += 2;
    for(int i = 0; i < ((n * n + 1) / 2 - 2 * n + 1) / 4; i++){
        int a = i / (n / 2);
        int b = i % (n / 2);
        c[1 + a][1 + b] = x;
        x += 2;
        c[n - a][1 + b] = x;
        x += 2;
        c[1 + a][n - b] = x;
        x += 2;
        c[n - a][n - b] = x;
        x += 2;
    }
    x = 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!c[i][j]){
                c[i][j] = x;
                x += 2;
            }
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}