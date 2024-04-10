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
string s, a, b;
int i, j, h, cnt1, cnt2, ans1, ans2, ds[200], da[200], db[200];

int main()
{
    cin >> s >> a >> b;
    cnt1 = cnt2 = s.size();
    for( i = 0; i < s.size(); i++ )ds[s[i]]++;
    for( i = 0; i < a.size(); i++ )da[a[i]]++;
    for( i = 0; i < b.size(); i++ )db[b[i]]++;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( da[c] )cnt1 = min(cnt1, ds[c] / da[c]);
    }
    for( i = 0; i <= cnt1; i++ ){
        cnt2 = s.size();
        for( char c = 'a'; c <= 'z'; c++ ){
            if( db[c] )cnt2 = min(cnt2, ds[c] / db[c]);
        }
        if( i + cnt2 > ans1 + ans2 ){
            ans1 = i;
            ans2 = cnt2;
        }
        for( char c = 'a'; c <= 'z'; c++ )ds[c] -= da[c];
    }
    for( i = 1; i <= ans1; i++ )cout << a;
    for( i = 1; i <= ans2; i++ )cout << b;
    for( char c = 'a'; c <= 'z'; c++ )ds[c] = 0;
    for( i = 0; i < s.size(); i++ )ds[s[i]]++;
    for( char c = 'a'; c <= 'z'; c++ ){
        ds[c] -= ans1 * da[c];
        ds[c] -= ans2 * db[c];
        for( j = 1; j <= ds[c]; j++ )cout << c;
    }
}