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
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
//#define int long long
using namespace std;
//const long long maxn = 100010, mod = 1e9 + 7, maxa = 20100, maxb = 23, base = 737, base2 = 3079, mod2 = 242121643;
//const long long inf = 2e18 + 13;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=2e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;


ll dre;

ll fen[2*maxn];


ll finds(ll p){
    return fen[p+1];
}
void update(int p,ll v){
    p++;
    fen[p]=(fen[p]+v)%mod;
}
void updatee(int l,int r,ll v){
    update(l,v);
    update(r+1,-v);
}
ll poww(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=(b>>1);       
    }
    return ans;
}

ll d[maxn];
ll tav[maxn];

int main(){

dre++;
    ll n,kk;
    cin>>n>>kk;
    for(ll i=0;i<maxn;i++){
        tav[i]=poww(i,n);
    }dre++;

dre++;

dre++;

    d[1]=1;
    for(int i=1;i<=kk;i++){dre++;

        for(int j=2*i;j<=kk;j+=i){
            d[j]=(d[j]-d[i])%mod;
        }
    }dre++;
dre++;

    for(int i=1;i<=kk;i++){
        d[i]=(d[i]+mod)%mod;
    }dre++;
dre++;

    for(int i=1;i<=kk;i++){
        for(int j=i;j<=kk;j+=i){
            updatee(j,j+(i-1),(d[i]*tav[j/i])%mod);
        }
    }
dre++;
dre++;
    fen[0]%=mod;
    fen[0]+=mod;
    fen[0]%=mod;
    for(ll i=1;i<maxn;i++){
        fen[i]=(fen[i]+fen[i-1]+mod)%mod;
    }   
    ll ans=0;dre++;

    for(int i=1;i<=kk;i++){dre++;

        ans=(ans+(finds(i)^i))%mod;
    }dre++;

    cout<<ans;
}