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

lli x = 1989, i, j, h, y, n, k, l;
string s;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> s;
        l = s.size() - 4;
        lli ans = 0, pow = 1, cnt = -1;
        for( j = 4; j < s.size(); j++ )
            ans = ans * 10 + s[j] - '0';
        for( j = 1; j <= l; j++ ){
            cnt += pow;
            pow *= 10;
        }
        //k += pow;
        while( ans < x + cnt )
            ans += pow;
        cout << ans << endl;
    }
}