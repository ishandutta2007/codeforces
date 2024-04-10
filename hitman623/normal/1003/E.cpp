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
int n,d,k,vis[500005];
vi a[500005];
vii edges;
int bfs(int node){
    int ans=node;
    queue<int> q;
    memset(vis,0,sizeof vis);
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        auto d=q.front();
        q.pop();
        for(auto i:a[d]){
            if(!vis[i]){
                q.push(i);
                vis[i]=vis[d]+1;
                ans=i;
            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>d>>k;
    if(n==1){
        cout<<"NO"<<endl;
        return;
    }
    if(k==1){
        if(n>2 || d>1){
            cout<<"NO"<<endl;
            return;
        }
        else{
            cout<<"YES"<<endl;
            cout<<"1 2"<<endl;
            return;
        }
    }
    if(k==2){
        if(n==d+1){
            cout<<"YES"<<endl;
            rep(i,1,n){
                cout<<i<<" "<<1+i<<endl;
            }
            return ;
        }
        cout<<"NO"<<endl;
        return;
    }
    priority_queue<pair<pii,int>> pq;
    rep(i,2,d+1){
        edges.pb({i,i-1});
        pq.push({{min(i-1,d+1-i),k-2},i});
    }
    edges.pb({d,d+1});
    int cur=d+2;
    rep(i,0,n-d-1){
        if(pq.empty()){
            cout<<"NO"<<endl;
            return;
        }
        auto g=pq.top();
        pq.pop();
        if(g.x.x==0){
            cout<<"NO"<<endl;
            return;
        }
        edges.pb({cur,g.y});
        g.x.y--;
        if(g.x.x!=1){
            pq.push({{g.x.x-1,k-1},cur});
        }
        if(g.x.y){
            pq.push(g);
        }
        cur++;
    }
    for(auto i:edges){
        a[i.x].pb(i.y);
        a[i.y].pb(i.x);
    }
    int w=bfs(1);
    w=bfs(w);
    if(vis[w]-1==d and sz(edges)==n-1){
        cout<<"YES"<<endl;
        for(auto i:edges){
            cout<<i.x<<" "<<i.y<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
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