#include <bits/stdc++.h>

#define int         long long
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
int n;
void solve(){
    cin>>n;
    int three=0,seven=0;
    while((seven+1)*(seven+1)<=n) seven++;
    while((three+1)*three/2*seven<=n) three++;
    while((three-1)*three/2*(seven+1)<=n) seven++;
    n-=three*(three-1)/2*seven;
    string ans;
    ans+="133";
    rep(i,0,n) ans+='7';
    rep(i,0,three-2) ans+='3';
    rep(i,0,seven) ans+='7';
    assert(sz(ans)<=1e5);
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}