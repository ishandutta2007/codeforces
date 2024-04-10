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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    vector < string > v;
    char c[10001];
    int a, i, j, k, h, f, g;
    string ans = "aaaa", t;
    sc( "%d%d", &a, &k );
    for( i = 1; i <= a * 4; i++ ){
        sc( "%s", &c );
        g = strlen(c);
        t = "";
        for( j = g - 1, f = 0; j >= 0; j-- ){
            if( c[j] == 'a' || c[j] == 'e' || c[j] == 'i' || c[j] == 'o' || c[j] == 'u' )f++;
            t += c[j];
            if( f == k )break;
        }
        if( f != k ){
            cout << "NO";
            return 0;
        }
        v.pb(t);
        if( i % 4 == 0 ){
            bool b1, b2, b3;
            b1 = b2 = b3 = 0;
            if( v[0] == v[1] && v[2] == v[3] )b1 = 1;
            if( v[0] == v[2] && v[1] == v[3] )b2 = 1;
            if( v[0] == v[3] && v[2] == v[1] )b3 = 1;
            if( b1 && (!b2 || !b3) ){
                if( ans == "aaaa" )ans = "aabb";
                else if( ans != "aabb" ){
                    cout << "NO";
                    return 0;
                }
            }
            if( b2 && (!b3 || !b1) ){
                if( ans == "aaaa" )ans = "abab";
                else if( ans != "abab" ){
                    cout << "NO";
                    return 0;
                }
            }
            if( b3 && (!b2 || !b1) ){
                if( ans == "aaaa" )ans = "abba";
                else if( ans != "abba" ){
                    cout << "NO";
                    return 0;
                }
            }
            if( !b1 && !b2 && !b3 ){
                cout << "NO";
                return 0;
            }
            v.clear();
        }
    }
    cout << ans;
}