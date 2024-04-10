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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s, t;
    int i, j, h, k, g;
    cin >> s >> k;
    g = int(s.size()) / k;
    if( int(s.size()) % k ){
        cout << "NO";
        return 0;
    }
    for( i = 0; i < k; i++ ){
        t = "";
        for( j = i * g; j < i * g + g; j++ )t += s[j];
        for( j = 0; j < t.size() / 2; j++ ){
            if( t[j] != t[t.size() - j - 1] ){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}