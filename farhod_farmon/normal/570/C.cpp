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
pair < int, int > p[300001];
int l, r, i, j, h, a, b, cnt, x;
string s;
char c;

int main()
{
    cin >> a >> b;
    cin >> s;
    for( i = 0; i < a; i++ ){
        if( s[i] != '.' )continue;
        if( s[i + 1] == '.' )cnt++;
        if( i && s[i - 1] == '.' )p[i].fi = p[i - 1].fi;
        else p[i].fi = i;
    }
    for( i = a - 1; i >= 0; i-- ){
        if( s[i] != '.' )continue;
        if( s[i + 1] == '.' )p[i].se = p[i + 1].se;
        else p[i].se = i;
    }
    for( i = 1; i <= b; i++ ){
        cin >> x >> c;
        x--;
        if( c != '.' && s[x] != '.' || c == '.' && s[x] == '.' ){
            cout << cnt << endl;
            continue;
        }
        s[x] = c;
        if( c == '.' ){
            if( x && s[x - 1] == '.' )cnt++;
            if( s[x + 1] == '.' )cnt++;
        }
        else{
            if( x && s[x - 1] == '.' )cnt--;
            if( s[x + 1] == '.' )cnt--;
        }
        cout << cnt << endl;
    }
}