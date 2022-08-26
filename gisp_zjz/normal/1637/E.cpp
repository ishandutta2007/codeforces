#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int>pi;
typedef long long ll;
int _,n,m,b[1000005];
set<pi> s;
map<int,int>cnt;
map<int,vi> v;
vi a;
int solve(vi &x,vi &y,int o){
    if (x.size()>y.size()) return solve(y,x,o);
    priority_queue<pi> q;
    while (!q.empty()) q.pop();
    for (int i=0;i<x.size();i++){
        if (!o) b[i]=y.size()-1; else b[i]=i-1;
        if (b[i]>=0) q.push((pi){x[i]+y[b[i]],i});
    }
    while (!q.empty()){
        pi tmp=q.top(); q.pop();
        int i=tmp.S;
        if (s.find((pi){x[i],y[b[i]]})==s.end()) return tmp.F;
        b[i]--;
        if (b[i]>=0) q.push((pi){x[i]+y[b[i]],i});
    }
    return 0;
}
void solve(){
    scanf("%d%d",&n,&m);
    cnt.clear();
    s.clear();
    v.clear();
    a.clear();
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        cnt[x]++;
    }
    for (int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        s.insert((pi){x,y});
        s.insert((pi){y,x});
    }
    for (auto x:cnt) v[x.S].pb(x.F);
    for (auto x:v) a.pb(x.F);
    ll ans=0;
    int m=a.size();
    for (int i=0;i<m;i++){
        int x=a[i];
        ans=max(ans,2ll*x*solve(v[x],v[x],1));
    }
    for (int i=0;i<m;i++)
        for (int j=i+1;j<m;j++){
            int x=a[i],y=a[j];
            ans=max(ans,1ll*(x+y)*solve(v[x],v[y],0));
        }
    printf("%lld\n",ans);
}
int main(){
    cin >> _;
    while (_--) solve();
    return 0;
}