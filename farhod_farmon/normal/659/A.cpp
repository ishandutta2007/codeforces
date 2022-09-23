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

int n, a, b;

int main()
{
    cin >> n >> a >> b;
    a += b;
    while( a <= 0 )
        a += n;
    while( a > n )
        a -= n;
    cout << a << endl;
}