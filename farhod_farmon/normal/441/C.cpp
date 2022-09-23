//http://informatics.mccme.ru/mod/statements/view3.php?id=277&chapterid=310#1

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
    int a,b,k,cnt=0,i=1,j=0,d=2,d1=0,d2=0;
    cin>>a>>b>>k;
    while( i<=a ){
        if( d==2 ){
            d=0;
            cnt++;
            if( cnt==k )d1=1;
            if( d1 && !d2 ){
                d2=1;
                cout<<endl;
                cout<<a*b-(k-1)*2<<" ";
            }
            else if( !d2 && !d1 ) cout<<endl<<"2 ";
        }
        if( i%2==1 )j++;
        else j--;
        if( j>b || j<=0 ){
             i++;
             //cout<<j<<" ";
             if( i%2==1 )j=1;
             else j=b;
        }
        d++;
        if( i<=a && j<=b )cout<<i<<" "<<j<<" ";
    }
}