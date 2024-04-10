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
#define fout freopen( "output.txt", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a,b;
vector < int > v[100001];
bool used[100001];

void dfs( int x )
{
    used[x]=true;
    for( int i=0; i<v[x].size(); i++ ){
        int to=v[x][i];
        if( !used[to] )dfs(to);
    }
    cout<<x<<" ";
}

int main()
{
    cin>>a>>b;
    for( int i=1; i<=b; i++ ){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    for( int i=1; i<=a; i++ ){
        if( !used[i] )dfs(i);
    }
}