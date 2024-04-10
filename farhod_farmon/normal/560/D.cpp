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

string rec( string s )
{
    int i;
    if( s.size() % 2 )return s;
    string s1, s2, t1 = "", t2 = "";
    for( i = 0; i < s.size() / 2; i++ )t1 += s[i];
    for( i = s.size() / 2; i < s.size(); i++ )t2 += s[i];
    s1 = rec(t1);
    s2 = rec(t2);
    return min(s1, s2) + max(s1, s2);
}

int main()
{
    string s, t;
    cin >> s >> t;
    s = rec(s);
    t = rec(t);
    if( s == t )cout << "YES";
    else cout << "NO";
}