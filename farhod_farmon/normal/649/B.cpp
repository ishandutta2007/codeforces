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

lli n, m, k, a, b, c, d, p1, p2, e1, e2;

int main()
{
    cin >> n >> m >> k;
    cin >> a >> b;
    p1 = (a - 1) / (m * k) + 1;
    p2 = (b - 1) / (m * k) + 1;
    a -= (p1 - 1) * (m * k);
    b -= (p2 - 1) * (m * k);
    e1 = (a - 1) / k + 1;
    e2 = (b - 1) / k + 1;
    c = min((e1 - 1) * 5, 10 + e1 - 1);
    d = min((e2 - 1) * 5, 10 + e2 - 1);
    if( p1 > p2 )
        swap(p1, p2);
    if( p1 == p2 ){
        a = abs(e1 - e2);
        cout << min(a * 5, 10 + a) << endl;
    }
    else
        cout << c + d + min(p2 - p1, p1 + n - p2) * 15 << endl;
}