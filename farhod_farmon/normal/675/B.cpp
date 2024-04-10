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

lli n, a, b, c, d, cnt;

int main()
{
    cin >> n >> a >> b >> c >> d;
    for(lli i = 1; i <= n; i++){
        lli x2 = i + a + b - a - c;
        lli x3 = i + a + b - c - d;
        lli x4 = i + a + b - b - d;
        cnt += x2 >= 1 && x3 >= 1 && x4 >= 1 && x2 <= n && x3 <= n && x4 <= n;
    }
    cout << cnt * n  << endl;
}