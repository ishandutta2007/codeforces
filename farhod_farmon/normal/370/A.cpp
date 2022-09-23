#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int a, b, c, d;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c >> d;
    cout << (a != c) + (b != d) << " " << ((a + b) % 2 == (c + d) % 2 ? 1 + !(a - b == c - d || a + b == c + d) : 0) << " " << max(abs(a - c), abs(b - d)) << endl;
}