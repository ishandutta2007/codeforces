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

using namespace std;

long double x[12][10002];
int n, t, i, j, h, cnt;

int main()
{
    cin >> n >> t;
    x[1][1] = t;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            if(x[i][j] < 1)
                continue;
            cnt++;
            x[i][j] -= 1;
            x[i + 1][j] += x[i][j] / 2.0;
            x[i + 1][j + 1] += x[i][j] / 2.0;
        }
    }
    cout << cnt << endl;
}