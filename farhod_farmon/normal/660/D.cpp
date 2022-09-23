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

map < pair < double, double >, int > m, t;
map < pair < double, double >, int > :: iterator it;
double x[2001], y[2002];
int i, j, cnt, n;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x[i] >> y[i];
        for( j = 1; j < i; j++ ){
            double sl = (y[i] - y[j]) / (x[i] - x[j]);
            double f = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if( x[i] != x[j] )
                m[mp(sl, f)]++;
            else
                t[mp(f, f)]++;
        }
    }
    for( it = m.begin(); it != m.end(); it++ )
        cnt += it->se * (it->se - 1) / 2;
    for( it = t.begin(); it != t.end(); it++ )
        cnt += it->se * (it->se - 1) / 2;
    cout << cnt / 2 << endl;
}