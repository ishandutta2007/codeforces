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
int m,n,k,t,a[200005],l[200005],r[200005],d[200005];
bool check(int w){
    vii v;
    rep(i,0,k){
        if(d[i]>w){
            v.pb({l[i]-1,-1});
            v.pb({r[i],1});
        }
    }
    if(sz(v)==0) return 1;
    sort(all(v));
    int cur=0,last=v[0].x,ans=0;
    rep(i,0,sz(v)){
        cur-=v[i].y;
        if(cur==0){
            ans+=2*(v[i].x-last);
            if(i+1<sz(v)) last=v[i+1].x;
        }
    }
    return ans+n+1<=t;
}
void solve(){
    cin>>m>>n>>k>>t;
    rep(i,0,m) cin>>a[i];
    rep(i,0,k) cin>>l[i]>>r[i]>>d[i];
    sort(a,a+m);
    reverse(a,a+m);
    int lo=-1,hi=m;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(a[mid])) lo=mid;
        else hi=mid;
    }
    cout<<lo+1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}