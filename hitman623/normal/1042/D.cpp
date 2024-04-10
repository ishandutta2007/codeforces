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
int n,k,a[200005],ans;
mi bit;
void update(int x,int y=1){
    x+=4e14;
    for(;x<=1e16;x+=x&(-x)) bit[x]+=y;
}
int query(int x){
    x+=4e14;
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x];
    return res;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        if(i) a[i]+=a[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans+=query(a[i]+k-1);
        update(a[i]);
    }
    ans+=query(k-1);
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