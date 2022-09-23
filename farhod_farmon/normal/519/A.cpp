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
    int a=8,i,j,cnt=0;
    map <char, int> m;
    m['q']=m['Q']=9;
    m['r']=m['R']=5;
    m['b']=m['B']=3;
    m['n']=m['N']=3;
    m['p']=m['P']=1;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            char x;
            cin>>x;
            if( x<97 )cnt+=m[x];
            else cnt-=m[x];
        }
    }
    if( cnt>0 )cout<<"White";
    else if( cnt<0 )cout<<"Black";
    else cout<<"Draw";
    return 0;
}