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

using namespace std;

set < pair < int, int > > mx, mn;
int n, k, x[100001], ans, i, l;
vector < pair < int, int > > v;

int main()
{
    cin >> n >> k;
    for( i = l = 1; i <= n; i++ ){
        cin >> x[i];
        mx.insert(mp(-x[i], i));
        mn.insert(mp(x[i], i));
        while( -(mx.begin()->fi) - (mn.begin()->fi) > k ){
            mx.erase(mp(-x[l], l));
            mn.erase(mp(x[l], l));
            l++;
        }
        if( i - l + 1 >= ans ){
            if( i - l + 1 > ans ){
                ans = i - l + 1;
                v.clear();
            }
            v.pb(mp(l, i));
        }
    }
    cout << ans << " " << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i].fi << ' ' << v[i].se << endl;
}