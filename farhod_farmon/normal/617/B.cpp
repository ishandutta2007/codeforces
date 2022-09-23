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

const int N = 100100;

using namespace std;

lli cnt = 1, last = -1, i, n, x;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        if( !x )
            continue;
        if( last == -1 ){
            last = i;
            continue;
        }
        else{
            cnt *= (i - last);
            last = i;
        }
    }
    if( last == -1 )
        cout << 0 << endl;
    else
        cout << cnt << endl;
}