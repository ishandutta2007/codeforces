#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
vector<pair<int,ll> >edge[100001];
ll dis[100001];
bool vis[100001];
int pre[100001];
int main(){
    ios::sync_with_stdio(false);
    int n,m,p,q,r;
    cin >> n >> m;
    for(int i=1; i<=m ;i++){
        cin >> p >> q >> r;
        edge[p].push_back(make_pair(q,r));
        edge[q].push_back(make_pair(p,r));
    }
    for(int i=1; i<=n ;i++){
        dis[i]=1e15;vis[i]=false;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
    dis[1]=0;
    pq.push(make_pair(0,1));
    int cnt=0;
    while(!pq.empty()){
        cnt++;
        while(!pq.empty() && vis[pq.top().second]) pq.pop();
        if(pq.empty() || pq.top().second==n) break;
        pair<ll,int>cur=pq.top();
        pq.pop();
        vis[cur.second]=true;
        for(int i=0; i<edge[cur.second].size() ;i++){
            if(vis[edge[cur.second][i].first]) continue;
            if(dis[edge[cur.second][i].first]>dis[cur.second]+edge[cur.second][i].second){
                pre[edge[cur.second][i].first]=cur.second;
                dis[edge[cur.second][i].first]=dis[cur.second]+edge[cur.second][i].second;
                pq.push(make_pair(dis[edge[cur.second][i].first],edge[cur.second][i].first));
            }
        }
    }
    if(dis[n]==1e15){
        cout << -1 << endl;
        return 0;
    }
    vector<int>ans;
    ans.push_back(n);
    while(ans.back()!=1){
        ans.push_back(pre[ans.back()]);
    }
    for(int i=ans.size()-1; i>=0 ;i--){
        cout << ans[i] << ' ';
    }
}