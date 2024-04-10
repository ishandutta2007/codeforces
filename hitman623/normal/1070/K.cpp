#include <bits/stdc++.h>

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
int n,k,a[100005],s;
vi ans;
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>a[i],s+=a[i];
    if(s%k){
        cout<<"No"<<endl;
        return;
    }
    s/=k;
    int cur=0,cnt=0;
    rep(i,1,n+1){
        cur+=a[i];
        cnt++;
        if(cur>s){
            cout<<"No"<<endl;
            return;           
        }
        if(cur==s){
            ans.pb(cnt);
            cnt=0;
            cur=0;
        }
    }
    if(sz(ans)!=k){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
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