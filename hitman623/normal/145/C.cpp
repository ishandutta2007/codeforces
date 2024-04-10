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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int M=100006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
}
int C(int n,int r){
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int n,k,m=0,a[100005];
map<int,int> lucky_map;
bool is_lucky(int n){
    while(n){
        int dig = n%10;
        if(dig != 4 and dig != 7) return false;
        n/=10;
    }
    return true;
}
int ways[2][100005];
void solve(){
    compute();
    cin>>n>>k;
    rep(i,1,n+1){
        cin>>a[i];
        if(is_lucky(a[i])) lucky_map[a[i]]++;
        else m++;
    }
    vii lucky_vec(all(lucky_map));

    ways[sz(lucky_vec)&1][0]=1;

    for(int pos=sz(lucky_vec)-1;pos>=0;pos--){ // 1022
        rep(l,0,n+1){ // 100000
            ways[pos&1][l] = (ways[(pos+1)&1][l] + (l > 0 ? 1LL * ways[(pos+1)&1][l-1] * lucky_vec[pos].y : 0)) % hell;
        }
    }
    int ans=0;
    rep(l,0,k+1){
        if(k-l <= m) ans = (ans + 1LL * ways[0][l] * C(m, k-l))%hell;
    }
    cout<<ans<<endl;
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