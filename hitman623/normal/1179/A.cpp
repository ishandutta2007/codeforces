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

int n,q,a[100005],mx=-1,pos=-1;
vi v;
vii vv;
void solve(){
    cin>>n>>q;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        if(a[i]>mx){
            mx=a[i];
            pos=i;
        }
    }
    v.pb(min(a[0],a[1]));
    int cur=max(a[0],a[1]);
    vv.pb({a[0],a[1]});
    rep(i,2,n){
        v.pb(min(cur,a[i]));
        vv.pb({cur,a[i]});
        cur=max(cur,a[i]);
    }
    while(q--){
        int k;
        cin>>k;
        if(k<=sz(vv)){
            cout<<vv[k-1].x<<" "<<vv[k-1].y<<endl;
        }
        else{
            k-=sz(vv);
            k%=(n-1);
            k=(k-2+n)%(n-1);
            cout<<mx<<" "<<v[k]<<endl;
        }
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