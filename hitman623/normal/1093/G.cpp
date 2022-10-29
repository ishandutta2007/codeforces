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
int n,k,t[1<<5][400005];
void build(){
    rep(j,0,1<<k){
        for(int i=n-1;i>0;--i) t[j][i]=max(t[j][i<<1],t[j][i<<1|1]);
    }
}
void modify(int p,int val,int mask){
    p+=n;
    for(t[mask][p]=val;p>1;p>>=1) t[mask][p>>1]=max(t[mask][p],t[mask][p^1]);
}
int query(int l,int r,int mask){
    int res=-hell;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[mask][l++]);
        if(r&1) res=max(res,t[mask][--r]);
    }
    return res;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        vi v;
        rep(j,0,k){
            int x;
            cin>>x;
            v.pb(x);
        }
        rep(j,0,1<<k){
            int cur=0;
            rep(l,0,k){
                if((j>>l)&1) cur+=v[l];
                else cur-=v[l];
            }
            t[j][i+n]=cur;
        }
    }
    build();
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            cin>>pos;
            pos--;
            vi v;
            rep(j,0,k){
                int x;
                cin>>x;
                v.pb(x);
            }
            rep(j,0,1<<k){
                int cur=0;
                rep(l,0,k){
                    if((j>>l)&1) cur+=v[l];
                    else cur-=v[l];
                }
                modify(pos,cur,j);
            }
        }
        else{
            int l,r,ans=-hell;
            cin>>l>>r;
            l--,r--;
            rep(j,0,1<<k) ans=max(ans,query(l,r,j)+query(l,r,((1<<k)-1)^j));
            cout<<ans<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}