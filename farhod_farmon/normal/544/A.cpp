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
int k, i, j, d[200];
string s, t;
vector < string > v;
bool used[200];
int main ()
{
    cin >> k >> s;
    for( i = 0; i < s.size(); i++ ){
        k--;
        used[s[i]] = true;
        t = "";
        while( i < s.size() && (used[s[i]] || !k) ){
            t += s[i];
            i++;
        }
        i--;
        v.pb(t);
    }
    if( !k ){
        cout << "YES\n";
        for( i = 0; i < v.size(); i++ )cout << v[i] << endl;
    }
    else cout << "NO";
}