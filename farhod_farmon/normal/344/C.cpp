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

lli a, b, cnt;

int main()
{
    cin >> a >> b;
    if( b > a )swap(a, b);
    while( b ){
        cnt += a / b;
        a %= b;
        swap(a, b);
    }
    cout << cnt << endl;
}