#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long double a, b, ans = 1e9;
    cin >> a >> b >> n;
    for(int i = 1; i <= n; i++){
        long double x, y, v;
        cin >> x >> y >> v;
        ans = min(ans, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
    }
    cout << fixed << setprecision(9) << ans << endl;
}