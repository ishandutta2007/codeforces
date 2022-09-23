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

int n, p, i, j, h;
string s;

bool can( char c, int x )
{
    if( x > 0 && c == s[x - 1] )
        return false;
    if( x - 1 > 0 && c == s[x - 2] )
        return false;
    return true;
}

char is( char c, int x )
{
    while( c < 'a' + p )
        if( can(c, x) )
            break;
        else
            c++;
    return c;
}

int main()
{
    cin >> n >> p >> s;
    for( i = n - 1; i >= 0; i-- )
        if( is(s[i] + 1, i) < 'a' + p )
            break;
    if( i < 0 ){
        cout << "NO" << endl;
        return 0;
    }
    s[i] = is(s[i] + 1, i);
    for( i = i + 1; i < n; i++ )
        s[i] = is('a', i);
    cout << s << endl;
}