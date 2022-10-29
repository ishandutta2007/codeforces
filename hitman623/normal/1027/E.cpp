#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,limit;
int f[505],dp[505][505],exact_f[505];
int find_ways(int pos,int running_length){
    if(running_length > limit) return 0;
    if(pos==n+1) return 1;
    if(dp[pos][running_length]!=-1) return dp[pos][running_length]; 
    dp[pos][running_length]=(find_ways(pos+1, 1) + find_ways(pos+1, running_length+1))%hell;
    return dp[pos][running_length];
}
void solve(){
    cin>>n>>k;
    rep(l,1,n+1){
        rep(i,0,n+2){
            rep(j,0,n+2){
                dp[i][j]=-1;
            }
        }
        limit=l;
        f[l] = find_ways(1, 0);
    }
    rep(l,1,n+1){
        exact_f[l]=(f[l]-f[l-1]+hell)%hell;
    }
    int ans=0;
    rep(l,1,n+1){
        rep(r,1,n+1){
            if(l*r<k){
                ans = (ans + 1LL*exact_f[l]*exact_f[r])%hell;
            }
        }
    }
    cout<<(1LL*ans*(hell+1)/2)%hell<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}