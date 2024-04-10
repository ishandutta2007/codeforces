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

int n, i, t, c, kol, curt, curc, mxc, mxt;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> t >> c;
        if( i == 1 )curt = t, curc = c;
        else{
            int g = min(t - curt, curc);
            curc -= g;
            curt = t;
            curc += c;
        }
        mxc = max(mxc, curc);
    }
    cout << curt + curc << " " << mxc << endl;
}