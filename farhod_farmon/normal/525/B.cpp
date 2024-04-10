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
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s;
    int a,b[500001],i,j,k,l,d[500001]={};
    cin>>s>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        d[b[i]-1]++;
    }
    for( i=0; i<s.size()/2; i++ ){
        if( i>0 )d[i]+=d[i-1];
        if( d[i]%2!=0 ){
            swap(s[i],s[s.size()-i-1]);
        }
    }
    cout<<s;
}