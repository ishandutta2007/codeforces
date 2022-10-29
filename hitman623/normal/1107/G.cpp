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
#define hell        100000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a,d[300005],c[300005],v[300005],ans;
int L[300005],R[300005];
pii t[600005];
stack<int> stk;
void pre(){
    rep(i,1,n){
        while(!stk.empty() and v[stk.top()]<=v[i]) stk.pop();
        if(!stk.empty()) L[i]=stk.top();
        else L[i]=0;
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i=n-1;i>=1;i--){
        while(!stk.empty() and v[stk.top()]<=v[i]) stk.pop();
        if(!stk.empty()) R[i]=stk.top();
        else R[i]=n;
        stk.push(i);        
    }
}
void build(){
    for(int i=n-1;i>0;--i) t[i]={max(t[i<<1].x,t[i<<1|1].x),min(t[i<<1].y,t[i<<1|1].y)};
}
int query(int l,int r,int f){
    pii res={-hell,hell};
    if(l<0) res.y=0,l=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            res={max(res.x,t[l].x),min(res.y,t[l].y)};
            l++;
        }
        if(r&1){
            --r;
            res={max(res.x,t[r].x),min(res.y,t[r].y)};
        }
    }
    if(f) return res.x;
    else return res.y;
}
void solve(){
    cin>>n>>a;
    int cur=0;
    rep(i,0,n){
        cin>>d[i]>>c[i];
        cur+=a-c[i];
        t[i+n]={cur,cur};
        ans=max(ans,a-c[i]);
    }
    rep(i,1,n) v[i]=(d[i]-d[i-1])*(d[i]-d[i-1]);
    pre();
    build();
    rep(i,1,n){
        ans=max(ans,query(i,R[i]-1,1)-query(L[i]-1,i,0)-v[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}