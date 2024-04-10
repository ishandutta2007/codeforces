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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a,b[1001],i,cnt=0;
string s[1001];
map < string, int > m,m1,m2;

int main()
{
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>s[i]>>b[i];
        m[s[i]]+=b[i];
    }
    for( i = 1; i <= a; i++ )cnt = max(cnt, m[s[i]]);
    for( i=1; i<=a; i++ ){
        m1[s[i]]+=b[i];
        if( m1[s[i]]>=cnt && m[s[i]] == cnt ){
            cout<<s[i]<<endl;
            break;
        }
    }   
}