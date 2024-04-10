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
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s;
    char c[3], x, y;
    int a, i, j, cnt = 0, d[1001] = {}, c1, c2, l, r;
    bool used[200][200] = {};
    cin >> s;
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> c[1] >> c[2];
        used[c[1]][c[2]] = 1;
        used[c[2]][c[1]] = 1;
    }
    for( i = 1; i < s.size(); i++ ){
        if( used[s[i]][s[i - 1]] ){
            c1 = c2 = 0;
            j = i - 1;
            x = s[i];
            y = s[i - 1];
            while( j >= 0 ){
                if( s[j] == x )c1++;
                else if( s[j] == y )c2++;
                else break;
                j--;
            }
            j = i;
            while( j < s.size() ){
                if( s[j] == x )c1++;
                else if( s[j] == y )c2++;
                else break;
                j++;
            }
            cnt += min(c1, c2);
            i = j;
        }
    }
    cout << cnt;
}