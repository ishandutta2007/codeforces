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
int n, x, y, i, j, h;
pair < int, int > p[111];

int main()
{
    cin >> n >> x >> y;
    cin >> s;
    p[i].fi = 1;
    for( i = 1; i <= n; i++ ){
        if( i >= x && p[i - x].fi ){
            p[i].fi = p[i - x].fi + 1;
            p[i].se = x;
        }
        if( i >= y && p[i - y].fi ){
            p[i].fi = p[i - y].fi + 1;
            p[i].se = y;
        }
    }
    if( !p[n].fi ){
        cout << -1 << endl;
        return 0;
    }
    cout << p[n].fi - 1 << endl;
    vector < string > v;
    for( i = n; i >= 1; i-- ){
        t = "";
        for( j = i - p[i].se; j < i; j++ )t += s[j];
        v.pb(t);
        i = i - p[i].se + 1;
    }
    for( i = v.size() - 1; i >= 0; i-- )cout << v[i] << endl;
}