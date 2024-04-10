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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s, t = "CODEFORCES";
    int i, j = -1, j1 = t.size();
    cin >> s;
    if( s.size() < 10 ){
        cout << "NO";
        return 0;
    }
    i = -1;
    while( t[j + 1] == s[i + 1] ) j++,i++;
    i = s.size();
    while( j1 > 0 && i > 0 && s[i - 1] == t[j1 - 1] )i--, j1--;
    if( j1 < 1 || j >= 9 || j1 <= j + 1 )cout << "YES";
    else cout << "NO";
}