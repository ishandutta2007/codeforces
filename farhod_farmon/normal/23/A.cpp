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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int i,j,ans=0;
    string s,t;
    vector < string > v;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
        t="";
        for( j=i; j<s.size(); j++ ){
            t+=s[j];
            v.pb(t);
        }
    }
    for( i=0; i<v.size(); i++ ){
        for( j=0; j<v.size(); j++ ){
            int g=v[i].size();
            if( i!=j && v[i]==v[j] )ans=max( ans, g  );
        }
    }
    cout<<ans;
}