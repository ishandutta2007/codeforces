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

int n, s[101], a, x, y, i;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    cin >> x >> y;
    for( i = 1; i <= n; i++ ){
        int g1 = s[i - 1];
        int g2 = s[n] - s[i - 1];
        if( x <= g1 && g1 <= y && x <= g2 && g2 <= y ){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}