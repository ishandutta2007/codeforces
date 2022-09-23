#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n;
string s[101];
bool used[101];

string comb( string x, string y )
{
    string t = "";
    int sx = -1;
    int sy = -1;
    for( int i = 0; i < x.size(); i++ ){
        for( int j = 0; j < y.size(); j++ ){
            if( x[i] == y[j] ){
                sx = i;
                sy = j;
                break;
            }
        }
        if( sx != -1 )
            break;
    }
    if( sx == -1 )
        return t;
    if( sx > sy ){
        for( int i = 0; i < x.size(); i++ )t += x[i];
        for( int i = 0; i + x.size() - sx < y.size(); i++ )t += y[x.size() - sx + i];
    }
    else{
        for( int i = 0; i < y.size(); i++ )t += y[i];
        for( int i = 0; i + y.size() - sy < x.size(); i++ )t += x[y.size() - sy + i];
    }
    return t;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> s[i];
    for( int h = 1; h <= n; h++ ){
        for( int i = 1; i <= n; i++ ){
            if( used[i] )
                continue;
            for( int j = 1; j <= n; j++ ){
                if( used[j] || i == j )
                    continue;
                string t = comb(s[i], s[j]);
                if( t != "" ){
                    s[i] = t;
                    used[j] = true;
                }
            }
        }
    }
    string ans = "";
    for( int i = 1; i <= n; i++ ){
        if( used[i] )
            continue;
        ans += s[i];
    }
    cout << ans << endl;
}