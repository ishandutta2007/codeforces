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
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int ans=0,a,i,j,g;
bool used[2001];
vector < int > v[2001];
map< string, int > m;
string s,z,t;
void dfs( int x, int y )
{
    ans=max( ans, y );
    if( used[x] )return;
    used[x]=1;
    for( int h=0; h<v[x].size(); h++ ){
        dfs(v[x][h], y+1);
    }
}

int main()
{
    cin>>a;
    m["polycarp"]=0;
    for( i=1; i<=a; i++ ){
        cin>>s>>z>>t;
        for( j=0; j<s.size(); j++ ){
            if( s[j]<97 )s[j]+=32;
        }
        for( j=0; j<t.size(); j++ ){
            if( t[j]<97 )t[j]+=32;
        }
        if( m[s]==0 ){
            g++;
            m[s]=g;
        }
        v[m[t]].pb(m[s]);
    }
    dfs(0, 1);
    cout<<ans;
}