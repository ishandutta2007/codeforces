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
string s, t;
int i, cnt = 0, j, d[1000001], d1[1000001], g = 0, g1 = 0;
bool used[10000001];

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        if( s[i] == 'x' ){
            g++;
            d[g] = i;
            if( g1 > 0 ){
                g1--;
                g--;
                used[i] = true;
                used[d1[g1 + 1]] = true;
            }
        }
        else{
            g1++;
            d1[g1] = i;
            if( g > 0 ){
                g--;
                g1--;
                used[i] = true;
                used[d[g + 1]] = true;
            }
        }
    }
    for( i = 0; i < s.size(); i++ ){
        if( !used[i] ) cout << s[i];
    }
}