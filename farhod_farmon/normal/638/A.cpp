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

int n, a;

int main()
{
    cin >> n >> a;
    if( a % 2 )cout << (a + 1) / 2 << endl;
    else cout << (n - a) / 2 + 1 << endl;
}