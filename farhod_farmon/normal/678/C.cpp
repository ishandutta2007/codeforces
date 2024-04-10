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

lli n, a, b, p, q;

int main()
{
    cin >> n >> a >> b >> p >> q;
    cout << (n / a) * p + (n / b) * q - (n / (a * b / __gcd(a, b))) * min(p, q) << endl;
}