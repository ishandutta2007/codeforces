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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,res[200005],arr[200005],cnt;
pii query(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int x=arr[l],f=1;
    cin>>x>>f;
    cnt++;
    return {x,f};
}
void go(int l,int r,int a,int b){
    if(a==b){
        rep(i,l,r+1) res[i]=a;
        return;
    }
    if(l==r-1){
        res[l]=a;
        res[r]=b;
        return;
    }
    pii ww=query(l,r);
    if(ww.y==r-l){
        if(ww.x==a) rep(i,l,r) res[i]=a;
        if(ww.x==b) rep(i,l+1,r+1) res[i]=b;
        res[l]=a;
        res[r]=b;
        return;
    }
    if(ww.x==a){
        rep(i,l,l+ww.y){
            res[i]=a;
        }
        go(l+ww.y,r,query(l+ww.y,l+ww.y).x,b);
        return;
    }
    if(ww.x==b){
        rep(i,r-ww.y+1,r+1){
            res[i]=b;
        }
        go(l,r-ww.y,a,query(r-ww.y,r-ww.y).x);
        return;
    }
    int mid=(l+r)/2;
    int w=query(mid,mid).x;
    go(l,mid,a,w);
    go(mid,r,w,b);
}
void solve(){
    cin>>n;
    go(1,n,query(1,1).x,query(n,n).x);
    set<int> st;
    cout<<"! ";
    rep(i,1,n+1){
        cout<<res[i]<<" ";
        st.insert(res[i]);
    }
    assert(cnt<=4*sz(st));
    cout<<endl;
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}