#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>

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

const int mod = 1e9 + 7;

using namespace std;

lli m, dd, d[2002][2002][2];

lli G( string s )
{
    lli cnt = 0;
    for( lli i = 0; i < s.size(); i++ ){
        if( i % 2 && s[i] - '0' != dd )return 0;
        if( i % 2 == 0 && s[i] - '0' == dd )return 0;
        cnt = (cnt * 10 + (s[i] - '0')) % m;
    }
    return cnt == 0;
}

lli M( string s )
{
    lli i, j, h, k;
    for( i = 0; i < s.size(); i++ ){
        for( j = 0; j < m; j++ ){
            d[i][j][0] = d[i][j][1] = 0;
        }
    }
    for( i = 1; i < s[0] - '0'; i++ ){
        if( i == dd )continue;
        d[0][i % m][0]++;
    }
    if( s[0] - '0' != dd )d[0][(s[0] - '0') % m][1]++;
    for( i = 0; i < s.size() - 1; i++ ){
        for( j = 0; j < m; j++ ){
            for( h = 0; h < 2; h++ ){
                for( k = 0; k <= 9; k++ ){
                    if( i % 2 == 1 && k == dd )continue;
                    if( i % 2 == 0 && k != dd )continue;
                    if( h == 1 && k > s[i + 1] - '0' )continue;
                    lli g = h & (s[i + 1] - '0' == k);
                    d[i + 1][(j * 10 + k) % m][g] = (d[i + 1][(j * 10 + k) % m][g] + d[i][j][h]) % mod;
                }
            }
        }
    }
    return (d[s.size() - 1][0][0] + d[s.size() - 1][0][1]) % mod;
}

int main()
{
    string a, b;
    cin >> m >> dd >> a >> b;
    cout << (M(b) - M(a) + G(a) + mod) % mod << endl;
}