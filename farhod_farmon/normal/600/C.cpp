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

int n, i, j, h, d[200];
string s;
char x;
vector < char > v;

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i++ )d[s[i]]++;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( d[c] % 2 )v.pb(c);
    }
    for( i = 0, j = v.size() - 1; i < j; i++, j-- ){
        d[v[i]]++;
        d[v[j]]--;
    }
    x = 1;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( d[c] % 2 )x = c;
        for( i = 0; i < d[c] / 2; i++ )cout << c;
    }
    if( x != 1 )cout << x;
    for( char c = 'z'; c >= 'a'; c-- ){
        for( i = 0; i < d[c] / 2; i++ )cout << c;
    }
}