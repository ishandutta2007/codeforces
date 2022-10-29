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
int n,a[200005],pre_prod[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        if(a[i]>0) a[i]=1;
        else a[i]=-1;
    }
    pre_prod[0]=1;
    rep(i,1,n+1){
        pre_prod[i]=pre_prod[i-1]*a[i];
    }
    int pos=0,neg=0;
    rep(i,0,n+1){
        if(pre_prod[i]>0) pos++;
        else neg++;
    }
    cout<<1LL*neg*pos<<" "<<1LL*neg*(neg-1)/2+1LL*pos*(pos-1)/2<<endl; 
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