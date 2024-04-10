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
int a, x, y, z;
vector < int > v, v1;
bool used[101];
string ans1;

void ans( int x1, int y1, int g )
{
    if( used[g] )return;
    used[g] = 1;
    for( int i = 0; i < v.size(); i++ ){
        if( (v[i] < x1 && x1 < v1[i]) || (v[i] < y1 && y1 < v1[i]) ){
            ans(v[i], v1[i], i);
        }
    }
}

int main()
{
    cin >> a;
    for( int i = 1; i <= a; i++ ){
        cin >> x >> y >> z;
        for( int j = 0; j < v.size(); j++ )used[j] = 0;
        if( x == 1 ){
            v.pb(y);
            v1.pb(z);
        }
        else{
            ans(v[y - 1], v1[y - 1], y - 1);
            if( used[z - 1] )cout << "YES\n";
            else cout << "NO\n";
        }
    }
}