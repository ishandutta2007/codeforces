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
int n,a[300005],nxt[300005],ans[300005];
void pre(){
    stack<int> stk;
    for(int i=3*n-1;i>=0;i--){
        while(!stk.empty() and a[stk.top()]<a[i]) stk.pop();
        if(!stk.empty()) nxt[i]=stk.top();
        else nxt[i]=3*n;
        stk.push(i);
    }
}
const int N=300005;
int t[2*N];
void build(){
    for(int i=3*n-1;i>0;--i) t[i]=min(t[i<<1],t[i<<1|1]);
}
int query(int l,int r){
    int res=hell;
    for(l+=3*n,r+=3*n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(r&1) res=min(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,n,3*n) a[i]=a[i-n];
    pre();
    rep(i,0,3*n) t[i+3*n]=a[i];
    build();
    for(int i=3*n-1;i>=0;i--){
        int lo=i,hi=nxt[i]+1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(query(i,mid)<(a[i]+1)/2) hi=mid;
            else lo=mid;
        }
        if(lo!=nxt[i]) ans[i]=lo-i+1;
        else ans[i]=nxt[i]-i+ans[nxt[i]];
    }
    rep(i,0,n){
        if(ans[i]<2*n) cout<<ans[i]<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}