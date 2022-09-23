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

const int N = 500100;

using namespace std;

char s[N], c;
int n, m, i, j, h, l[N], r[N], cur, k[N];
vector < int > v;

int main()
{
    sc( "%d%d%d%c", &n, &m, &cur, &c );
    for( i = 1; i <= n; i++ ){
        sc( "%c", &s[i] );
        if( s[i] == '(' )
            v.pb(i);
        else{
            k[v.back()] = i;
            k[i] = v.back();
            v.pop_back();
        }
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[0] = 1;
    l[n + 1] = n;
    sc( "%c", &c );
    for( i = 1; i <= m; i++ ){
        sc( "%c", &c );
        //cout << c;
        if( c == 'L' )
            cur = l[cur];
        else if( c == 'R' )
            cur = r[cur];
        else{
            //cout << cur << endl;
            int x = cur, y = k[cur];
            if( x > y )
                swap(x, y);
            r[l[x]] = r[y];
            l[r[y]] = l[x];
            if( r[y] > n )
                cur = l[x];
            else
                cur = r[y];
        }
    }
    //cout << endl;
    i = r[0];
    while( i <= n ){
        pr( "%c", s[i] );
        //cout << i << endl;
        i = r[i];
    }
}