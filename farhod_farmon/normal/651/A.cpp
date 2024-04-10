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

using namespace std;

int a, b, cnt;

int main()
{
    cin >> a >> b;
    while( a > 0 && b > 0 && (a != 1 || b != 1) ){
        if( a < b )a++, b -= 2;
        else b++, a -= 2;
        cnt++;
        a = min(a, 100);
        b = min(b, 100);
    }
    cout << cnt << endl;
}