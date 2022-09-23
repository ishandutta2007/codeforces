#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 1011;

using namespace std;

char c[N][N];
int all, n, m, a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if(c[i][j] == '.')
                continue;
            a[i]++;
            b[j]++;
            all++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int g = 0;
            if(c[i][j] == '*')
                g = 1;
            if(a[i] + b[j] - g == all){
                cout << "YES" << endl;
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}