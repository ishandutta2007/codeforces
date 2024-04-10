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
int n,m,s[101],h[101],a[101],l[101],r[101];
void solve(){
    cin>>n>>m;
    rep(i,1,m+1) cin>>s[i]>>h[i];
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,m+1){
        l[i]=0;
        int cur=h[i];
        for(int j=s[i];j>=1;j--){
            cur+=a[j];
            if(cur<0){
                l[i]=j+1;
                break;
            }
        }
        r[i]=n+1;
        cur=h[i];
        for(int j=s[i];j<=n;j++){
            cur+=a[j];
            if(cur<0){
                r[i]=j-1;
                break;
            }
        }
    }
    rep(i,1,n+1){
        vii on_l,on_r;
        vi on_i;
        rep(j,1,m+1){
            if(s[j]>i) on_r.pb({l[j],j});
            else if(s[j]<i) on_l.pb({r[j],j});
            else on_i.pb(j);
        }
        sort(all(on_l));
        sort(all(on_r));
        reverse(all(on_l));
        bool can=0;
        if(sz(on_i)) can=1;
        if(sz(on_r) and on_r[0].x<=i) can=1;
        if(sz(on_l) and on_l[0].x>=i) can=1;
        int cur=i+1;
        for(auto j:on_r){
            if(j.x>cur) can=0;
            cur=max(cur,s[j.y]);
        }
        cur=i-1;
        for(auto j:on_l){
            if(j.x<cur) can=0;
            cur=min(cur,s[j.y]);
        }
        if(can){
            cout<<i<<endl;
            for(auto j:on_i) cout<<j<<" ";
            for(auto j:on_l) cout<<j.y<<" ";
            for(auto j:on_r) cout<<j.y<<" ";  
            return;
        }
    }
    cout<<-1<<endl;
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