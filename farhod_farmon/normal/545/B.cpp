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
string s, t, p;
int i, cnt, a, cnt1;
int main()
{
    cin >> s >> t;
    for( i = 0; i < s.size(); i++ ){
        if( s[i] != t[i] ){
            cnt++;
            if( cnt % 2 )p += s[i];
            else p += t[i];
        }
        else p += s[i];
    }
    if( cnt % 2 )cout << "impossible";
    else cout << p;
}