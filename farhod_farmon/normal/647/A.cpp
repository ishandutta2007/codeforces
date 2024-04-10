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

int n, cur, cnt, x, i;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        if( x > 3 )
            cur++;
        else
            cur = 0;
        if( cur == 3 )
            cur = 0,
            cnt++;
    }
    cout << cnt << endl;
}