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
    int a,i,j,cnt=0;
    string s;
    cin>>a>>s;
    for( i=1; i<=a; i++ ){
        for( j=0; j<s.size(); j++ ){
            int g=j;
            cnt=0;
            while( g<s.size() )cnt++,g+=i;
            if( cnt>=5 ){
            if( s[j]==s[j+i] && s[j]==s[j+(i*2)] && s[j]==s[j+i*3] && s[j]==s[j+i*4] && s[j]=='*' ){
                cout<<"yes";
                return 0;
            }
            }

        }
    }
    cout<<"no";
}