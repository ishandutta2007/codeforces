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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,v[100005],cnt,vis[100005],dis[100005],len,res=hell,p[100005],s[100005],par[100005],vv[100005];
mii mp;
vii a[100005];
int bfs(int node){
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    queue<int> q;
    q.push(node);
    dis[node]=0;
    par[node]=node;
    int ans=node;
    while(!q.empty()){
        auto d=q.front();
        q.pop();
        for(auto i:a[d]){
            if(vis[i.x]==0){
                q.push(i.x);
                dis[i.x]=dis[d]+i.y;
                vis[i.x]=1;
                par[i.x]=d;
                if(dis[i.x]>dis[ans]){
                    ans=i.x;
                }
            }
        }
    }
    return ans;
}
void dfs(int node,int par,int x1,int x2,int l){
    len=max(len,l);
    for(auto i:a[node]){
        if(i.x!=par and i.x!=x1 and i.x!=x2){
            dfs(i.x,node,x1,x2,l+i.y);
        }
    }
}
void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int x,y,l;
        cin>>x>>y>>l;
        a[x].pb({y,l});
        a[y].pb({x,l});
        mp[{x,y}]=l;
        mp[{y,x}]=l;
    }
    int l=bfs(1);
    int r=bfs(l);
    while(1){
        v[++cnt]=r;
        if(r==l) break;
        r=par[r];
    }
    rep(i,1,cnt+1){
        len=0;
        dfs(v[i],-1,v[i-1],v[i+1],0);
        vv[i]=len;
    }
    if(cnt<=k){
        int mx=0;
        rep(i,1,cnt+1){
            mx=max(mx,vv[i]);
        }
        cout<<mx<<endl;
        return;
    }
    rep(i,1,cnt+1){
        p[i]=max(vv[i],p[i-1]+mp[{v[i],v[i-1]}]);
    }
    for(int i=cnt;i>=1;i--){
        s[i]=max(vv[i],s[i+1]+mp[{v[i],v[i+1]}]);
    }
    deque<int> dq;
    rep(i,1,k){
        if(dq.empty() || vv[dq.back()]<vv[i]){
            dq.push_back(i);
        }
    }
    rep(i,k,cnt+1){
        if(dq.empty() || vv[dq.back()]<vv[i]){
            dq.push_back(i);
        }
        int cur=max({p[i-k+1],s[i],vv[dq.back()]});
        res=min(res,cur);
        if(dq.front()==i-k+1){
            dq.pop_front();
        }
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}