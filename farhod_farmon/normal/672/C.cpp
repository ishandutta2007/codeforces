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

const int N = 100100;

using namespace std;

long double tx, ty, ax, ay, bx, by, x, y, c1, c2, d[N][4];
pair < long double, pair < long double, long double > > f[N];
lli n, i, j, h;

long double le(long double x1, long double y1, long double x2, long double y2)
{
    return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    //d[0][1] = d[0][2] = d[0][3] = 1e15;
    for(i = 1; i <= n; i++){
        cin >> x >> y;
        f[i] = {le(x, y, tx, ty), {le(x, y, ax, ay), le(x, y, bx, by)}};
    }
    //cout << f[1].fi + f[2].fi + f[3].se.fi << endl;
    //sort(f + 1, f + n + 1);
    d[1][0] = f[1].fi * 2;
    d[1][1] = f[1].se.fi + f[1].fi;
    d[1][2] = f[1].se.se + f[1].fi;
    d[1][3] = 1e15;
    for(i = 2; i <= n; i++){
        d[i][0] = d[i - 1][0] + f[i].fi * 2;
        d[i][1] = min(d[i - 1][1] + f[i].fi * 2, d[i - 1][0] + f[i].se.fi + f[i].fi);
        d[i][2] = min(d[i - 1][2] + f[i].fi * 2, d[i - 1][0] + f[i].se.se + f[i].fi);
        d[i][3] = min(d[i - 1][1] + f[i].se.se + f[i].fi, d[i - 1][2] + f[i].se.fi + f[i].fi);
        d[i][3] = min(d[i][3], d[i - 1][3] + f[i].fi * 2);
        //cout << d[i][1] << " " << d[i][2] << endl;
    }
    d[n][3] = min(d[n][3], min(d[n][1], d[n][2]));
    cout << fixed << setprecision(9) << d[n][3] << endl;
}