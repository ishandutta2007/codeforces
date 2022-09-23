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

int x[4], y[4];

bool can( int a, int b, int c )
{
    return x[a] == x[b] && x[a] == x[c] || y[a] == y[b] && y[a] == y[c];
}

bool can1( int a, int b, int c )
{
    if( !can(a, b, b) )
        return false;
    if( x[a] == x[b] ){
        if( y[a] > y[b] )
            swap(a, b);
        return y[c] <= y[a] || y[b] <= y[c];
    }
    if( y[a] == y[b] ){
        if( x[a] > x[b] )
            swap(a, b);
        return x[c] <= x[a] || x[b] <= x[c];
    }
    return false;
}

int main()
{
    for( int i = 1; i <= 3; i++ )
        cin >> x[i] >> y[i];
    if( can(1, 2, 3) )
        cout << 1 << endl;
    else if( can1(1, 2, 3) )
        cout << 2 << endl;
    else if( can1(1, 3, 2) )
        cout << 2 << endl;
    else if( can1(2, 3, 1) )
        cout << 2 << endl;
    else
        cout << 3 << endl;
}