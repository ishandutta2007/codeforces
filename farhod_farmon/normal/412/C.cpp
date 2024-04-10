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
#define fout freopen( "output.txt", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a,i,j,k,l;
    string s[100001],ans;
    char c;
    cin>>a;
    for( i=1; i<=a; i++ ) cin>>s[i];
    for( i=0; i<s[1].size(); i++ ){
        c=s[1][i];
        bool b1=false;
        for( j=1; j<=a; j++ ){
            if( s[j][i]=='?' )continue;
            b1=true;
            if( c=='?' )c=s[j][i];
            else if( s[j][i]!=c ){
                c='?';
                break;
            }
        }
        if( !b1 && c=='?' )ans+='a';
        else ans+=c;
    }
    cout<<ans;
}