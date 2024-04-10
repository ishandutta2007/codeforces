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

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;
    l /= v;
    d /= v;
    long long c = d / (g + r);
    long double f = 1.0 * (g + r) * c;
    if(f <= d && d < f + g){
        cout << fixed << setprecision(9) << l << endl;
    }
    else
        cout << fixed << setprecision(9) << f + g + r + l - d << endl;
}