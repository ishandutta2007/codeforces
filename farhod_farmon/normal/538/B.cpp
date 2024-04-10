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
    string s, t;
    int i = 0, j;
    vector < string > v;
    cin >> s;
    while( i < s.size() ){
        if( s[i] == '0' ){
            i++;
            continue;
        }
        t = "";
        for( j = i; j < s.size(); j++ ){
            if( s[j] > '0' ){
                t += '1';
                s[j]--;
            }
            else t += s[j];
        }
        v.pb(t);
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}