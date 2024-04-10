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
    vector < string > v,v1;
    int a,b[10001],d,i,j,k,m,n,cnt=100;
    string s[10001],t[10001];
    cin>>a>>d;
    for( i=1; i<=a; i++ ){
        cin>>s[i]>>t[i]>>b[i];
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            if( t[i]==s[j] && s[i]==t[j] && b[j]>b[i] && b[j]-b[i]<=d && s[j]!="1" && t[j]!="1" ){
                v.pb( s[i] );
                v1.pb( t[i] );
                for( int h=1; h<=a; h++ ){
                    if( (s[i]==s[h] && t[i]==t[h] || t[i]==s[h] && s[i]==t[h]) && i!=h ){
                        s[h]=t[h]="1";
                    }
                }
                s[i]=t[i]=s[j]=t[j]="1";
            }
        }
    }
    cout<<v.size()<<endl;
    for( i=0; i<v.size(); i++ )cout<<v[i]<<" "<<v1[i]<<endl;
    return 0;
}