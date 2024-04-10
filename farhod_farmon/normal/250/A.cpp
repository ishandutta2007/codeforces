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
int main()
{
    vector<int>v;
    int a,b[101],i,c=0,d=0,f=0,x=0,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if( b[i]<0 )f++;
    }
    if( f==0 ){
        cout<<1<<endl<<a;
        return 0;
    }
    cout<<(f+1)/2<<endl;
    for( i=1; i<=a; i++ ){
        if( b[i]<0 )c++;
        d++;
        if( c==2 ){
            cnt++;
            if( cnt==(f+1)/2-1 )x=i;
            if( cnt==(f+1)/2 )break;
            cout<<d<<" ";
            d=c=0;
        }
    }
    cout<<a-x;
}