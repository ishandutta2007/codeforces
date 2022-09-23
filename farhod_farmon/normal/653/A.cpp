#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100001;

using namespace std;

int n, x, i, d[1001];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        d[x]++;
    }
    for( i = 1; i <= 998; i++ ){
        if( d[i] && d[i + 1] && d[i + 2] ){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}