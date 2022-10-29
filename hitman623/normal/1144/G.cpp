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
int bit[2][200007];
void update(int f,int x,int y=1){
    x++;
    if(f==1) for(;x<=200005;x+=x&(-x)) bit[f][x]+=y;
    else for(;x<=200005;x+=x&(-x)) bit[f][x]=max(bit[f][x],y);
}
int query(int f,int x){
    x++;
    int res=0;
    if(f==1) for(;x>0;x-=x&(-x)) res+=bit[f][x];
    else for(;x>0;x-=x&(-x)) res=max(res,bit[f][x]);
    return res;
}
int n,a[200005],res[200005],ans[200005];
int check(vi v){
    rep(i,1,sz(v)) if(v[i]<=v[i-1]) return 0;
    return 1;
}
void go(int w){
    memset(res,0,sizeof res);
    memset(ans,0,sizeof ans);
    memset(bit,0,sizeof bit);
    vi v1,v2;
    for(int i=n-1;i>=0;i--){
        ans[i]=query(0,a[i]-1)+1;
        update(0,a[i],ans[i]);
        update(1,a[i],1);
    }
    rep(i,0,n){
        update(1,a[i],-1);
        if(ans[i]-1==query(1,a[i]-1) and (sz(v1)==0 or a[i]>v1.back())) res[i]=w,v1.pb(a[i]);
        else res[i]=1-w,v2.pb(a[i]);
    }
    reverse(all(v2));
    if(check(v1) and check(v2)){
        cout<<"YES"<<endl;
        rep(i,0,n) cout<<res[i]<<" ";
        cout<<endl;
        exit(0);
    }    
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    go(0);
    rep(i,0,n) a[i]=200003-a[i];
    go(1);
    cout<<"NO"<<endl;
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