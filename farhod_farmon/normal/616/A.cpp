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

string a, b, s;
int i, h;

int main()
{
    cin >> a >> b;
    h = max(a.size(), b.size());
    for( s = "", i = 0; i < h - a.size(); i++ )s += '0';
    a = s + a;
    for( s = "", i = 0; i < h - b.size(); i++ )s += '0';
    b = s + b;
    i = 0;
    while( i < a.size() && a[i] == b[i] )i++;
    if( i == a.size() )cout << "=" << endl;
    else if( a[i] < b[i] )cout << "<" << endl;
    else cout << ">" << endl;
}