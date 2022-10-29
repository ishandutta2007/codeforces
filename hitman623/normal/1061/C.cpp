#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
vi divisors[1000001];
vi d[1000006];
void process_seive(int n){
    rep(i,1,n+1){
        for(int j=i;j<=n;j+=i){
            divisors[j].emplace_back(i);
        }
    }
}
int n,a[100005],res;
void solve(){
    process_seive(1000000);
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        for(auto j:divisors[a[i]]){
            if(j<=n) d[j].emplace_back(i);
        }
    }
    vi ans;
    for(int i=n;i>=1;i--){
        vi temp(sz(d[i]));
        rep(j,0,sz(d[i])){
            int l=upper_bound(all(d[i+1]),d[i][j])-d[i+1].begin();
            if(l<sz(ans)) temp[j]=(ans[l]+1)%hell;
            else temp[j]=1;
        }
        ans.clear();
        swap(ans,temp);
        for(int j=sz(ans)-2;j>=0;j--) ans[j]=(ans[j]+ans[j+1])%hell;
    }
    cout<<ans[0]<<endl;
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