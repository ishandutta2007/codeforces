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
    string s,t,ans;
    vector < string > v;
    int a=0,i,j,cnt=0;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
        if( s[i]==',' || s[i]==':' )continue;
        else if( s[i]=='.' ){
            v.p_b();
            continue;
        }
        t="";
        for( j=i; j<s.size(); j++ ){
            if( s[j]==':' || s[j]=='.' || s[j]==',' ){
                i=j-1;
                break;
            }
            t+=s[j];
        }
        a=0;
        for( j=0; j<v.size(); j++ ){
            if( v[j]==t )a++;
        }
        v.pb(t);
        cnt+=a;
    }
    cout<<cnt;
    return 0;
}