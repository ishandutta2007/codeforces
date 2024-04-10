#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

string s, t;
lli i, j, ans, d[200001], l, r;

int main()
{
    cin >> s >> t;
    for( i = 0; i < int(s.size()); i++ ){
        if( i )d[i] = d[i - 1];
        if( s[i] == '1' )d[i]++;
    }
    for( i = 0; i < int(t.size()); i++ ){
        l = max(0ll, int(s.size()) - int(t.size()) + i);
        r = min(int(s.size()) - 1ll, i);
        if( t[i] == '0' ){
            if( l == 0 )ans += d[r];
            else ans += (d[r] - d[l - 1]);
        }
        else{
            if( l == 0 )ans += (r - l + 1) - d[r];
            else ans += (r - l + 1) - (d[r] - d[l - 1]);
        }
    }
    cout << ans << endl;
}