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

int d[101][3], a[101], n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 2)
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + 1;
        if(a[i] % 2)
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + 1;
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
    }
    d[n][0] = max(d[n][0], d[n][1]);
    d[n][0] = max(d[n][0], d[n][2]);
    cout << n - d[n][0] << endl;
}