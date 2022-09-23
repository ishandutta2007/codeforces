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
#define fin freopen( "cowart.in", "r", stdin );
#define fout freopen( "cowart.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli A,B,a,i,j,l[100001],t[100001],m[100001],s[10000001],d[10000001];
int main()
{
    cin>>A>>B>>a;
    for( i=1; i<=a; i++ )cin>>l[i]>>t[i]>>m[i];
    for( i=1; i<=5000000; i++ ){
        s[i]=A+(i-1)*B;
        d[i]=d[i-1]+s[i];
    }
    for( i=1; i<=a; i++ ){
        lli l1=l[i],r1=5000000,m1;
        while( l1<r1 ){
            m1=(l1+r1)/2;
            if( s[m1]<=t[i] && (d[m1+1]-d[l[i]-1]+t[i]-1)/t[i]<=m[i] && s[m1+1]<=t[i]  )l1=m1+1;
            else r1=m1;
        }
        if( s[l[i]]>t[i] )cout<<"-1\n";
        else cout<<l1<<endl;
    }
}