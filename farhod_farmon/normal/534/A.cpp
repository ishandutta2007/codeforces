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
int main()
{
    int a,i,j,d[500001];
    cin>>a;
    if( a==2 || a==1 ){
        cout<<"1\n1";
        return 0;
    }
    if( a==3 ){
        cout<<"2\n1 3";
        return 0;
    }
    if( a%2!=0 ){
        cout<<a<<"\n"<<a<<" ";
        a--;
    }
    else cout<<a<<"\n";
    for( i=1; i<=a; i++ )d[i]=i;
    for( i=1; i<=a/2; i++ ) cout<<d[i+a/2]<<" "<<d[i]<<" ";
}