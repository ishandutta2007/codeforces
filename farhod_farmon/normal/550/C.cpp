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

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s;
    int i, j, h, x;
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        if( s[i] == '0' ){
            cout << "YES" << endl << s[i];
            return 0;
        }
    }
    for( i = 0; i < s.size(); i++ ){
        x = s[i] - 48;
        if( x % 8 == 0 ){
            cout << "YES\n" << s[i];
            return 0;
        }
        for( j = i + 1; j < s.size(); j++ ){
            x = (s[i] - 48) * 10 + s[j] - 48;
            if( x % 8 == 0 ){
                cout << "YES\n" << s[i] << s[j];
                return 0;
            }
            for( h = j + 1; h < s.size(); h++ ){
                x = ((s[i] - 48) * 10 + s[j] - 48) * 10 + s[h] - 48;
                if( x % 8 == 0 ){
                    cout << "YES\n" << s[i] << s[j] << s[h];
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}