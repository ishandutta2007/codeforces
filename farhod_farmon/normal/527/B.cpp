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
    int used[1001][1001]={},a,i,j,cnt=0;
    string s,t;
    cin>>a>>s>>t;
    for( i=0; i<s.size(); i++ ){
        if( s[i]!=t[i] ){
            cnt++;
            used[s[i]][t[i]]=i;
        }
    }
    for( i=0; i<s.size(); i++ ){
        if( s[i]!=t[i] && used[t[i]][s[i]]!=0 ){
            cout<<cnt-2<<endl<<i+1<<" "<<used[t[i]][s[i]]+1;
            return 0;
        }
    }
    for( i=0; i<s.size(); i++ ){
        if( s[i]!=t[i] ){
            for( char c='a'; c<='z'; c++ ){
                if( used[t[i]][c] ){
                    cout<<cnt-1<<endl<<i+1<<" "<<used[t[i]][c]+1;
                    return 0;
                }
                if( used[c][s[i]] ){
                    cout<<cnt-1<<endl<<i+1<<" "<<used[c][s[i]]+1;
                    return 0;
                }
            }
        }
    }
    cout<<cnt<<"\n-1 -1";
}