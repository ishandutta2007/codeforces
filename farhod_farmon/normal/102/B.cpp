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
string s, t;
int cnt, i, x;

int main()
{
    cin >> s;
    while( s.size() > 1 ){
        cnt++;
        x = 0;
        t = "";
        for( i = 0; i < s.size(); i++ )x += s[i] - '0';
        while(x){
            t += char(x % 10 + '0');
            x /= 10;
        }
        s = t;
    }    
    cout << cnt << endl;
}