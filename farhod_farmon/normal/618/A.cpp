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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int n, i;
vector < int > v;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        v.pb(1);
        bool b1 = true;
        while( v.size() > 1 && v[v.size() - 1] == v[v.size() - 2] ){
            int x = v[v.size() - 1];
            v.p_b();
            v.p_b();
            v.pb(x + 1);
        }
    }
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}