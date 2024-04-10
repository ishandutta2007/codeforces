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
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "skidesign.in", "r", stdin );
#define fout freopen( "skidesign.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    bool used[1001]={};
    vector < int > p;
    int a,b,c[501],x[1001],ans=0,i,j,d[501]={};
    cin>>a>>b;
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=1; i<=b; i++ ){
        cin>>x[i];
        if( !used[x[i]] ){
            p.pb(x[i]);
            used[x[i]]=true;
        }
    }
    int cnt;
    for( i=1; i<=b; i++ ){
        cnt=0;
        for( j=0; j<p.size(); j++ ){
            if( x[i]==p[j] ){
                j--;
                break;
            }
            cnt+=c[p[j]];
        }
        while( j>=0 ){
            p[j+1]=p[j];
            j--;
        }
        p[0]=x[i];
        ans+=cnt;
    }
    cout<<ans;
}