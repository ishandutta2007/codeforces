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
int n,x,w,p[200005];
vii v,vv;
const int N=200005;
int t[2*N];
void modify(int p,int val){
    for(t[p+=n]=val;p>1;p>>=1) t[p>>1]=max(t[p],t[p^1]);
}
int query(int l,int r){
    if(l>r) return 0;
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[l++]);
        if(r&1) res=max(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x>>w;
        v.pb({x,w});
    }
    sort(all(v));
    rep(i,0,n){
        vv.pb({v[i].x+v[i].y,i});
    }
    sort(all(vv));
    rep(i,0,n){
        p[vv[i].y]=i;
    }
    rep(i,0,n){
        pii d={v[i].x-v[i].y,hell};
        int l=upper_bound(all(vv),d)-vv.begin()-1;
        modify(p[i],query(0,l)+1);
    }
    cout<<query(0,n-1)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}