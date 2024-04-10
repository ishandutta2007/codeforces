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
#define fin freopen( "skidesign.in", "r", stdin );
#define fout freopen( "skidesign.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    bool used[2][2][2001]={};
    int a,y,x,t,h,m,i,j=0,cnt=0,ans=0,f,f1,z;
    vector < pair < int, int > > v[2];
    cin>>a>>y;
    for( i=1; i<=a; i++ ){
        cin>>t>>h>>m;
        v[t].pb(mp(h,m));
    }
    for( f=0; f<=1; f++ ){
        x=y;
        f1=f;
        cnt=0;
        while(1){
            j=-1;
            for( i=0; i<v[f1].size(); i++ ){
                if( !used[f][f1][i] && v[f1][i].se>=j && v[f1][i].fi<=x ){
                    z=i;
                    j=v[f1][i].se;
                }
            }
            if( j==-1 )break;
            x+=v[f1][z].se;
            cnt++;
            used[f][f1][z]=1;
            f1=abs(f1-1);
        }
        ans=max( ans, cnt );
    }
    cout<<ans;
}