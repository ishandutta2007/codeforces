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

int n, x, i, h, j, y, l = 1, d[1000001];
char c;

int main()
{
    x = 1;
    d[1] = 1;
    while( cin >> c ){
        if( c == '=' )
            break;
        if( c == '?' )
            l++;
        else if( c == '-' ){
            d[l] = -1;
            x--;
        }
        else{
            d[l] = 1;
            x++;
        }
    }
    cin >> n;
    i = 1;
    while( x != n && i < l ){
        if( x > n && d[i] > 0 || x < n && d[i] < 0 ){
            i++;
            continue;
        }
        if( x < n ){
            y = min(n - x, n - 1);
            x += y;
            d[i] += y;
            i++;
        }
        else{
            y = min(x - n, n - 1);
            x -= y;
            d[i] -= y;
            i++;
        }
    }
    if( x != n ){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    cout << d[1];
    for( i = 2; i < l; i++ ){
        if( d[i] < 0 )
            cout << " - ";
        else
            cout << " + ";
        cout << abs(d[i]);
    }
    cout << " = " << n << endl;
}