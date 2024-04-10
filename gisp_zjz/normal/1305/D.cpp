#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
int d[maxn],n,vis[maxn];
vector <int> h[maxn];
queue <int> q;
void del(int u){
    for (auto v:h[u]){
        d[v]--;
        if (d[v]==1) q.push(v);
    }
}
int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); h[v].pb(u);
        d[u]++; d[v]++;
    }
    for (int i=1;i<=n;i++) if (d[i]==1) q.push(i);
    while (q.size()>=2){
        int u=q.front(); q.pop();
        int v=q.front(); q.pop();
        vis[u]=vis[v]=1;
        printf("? %d %d\n",u,v); fflush(stdout);
        int x; cin >> x;
        if (x==u||x==v){
            printf("! %d\n",x); return 0;
        }
        del(u); del(v);
    }
    int cnt=0;
    for (int i=1;i<=n;i++) if (!vis[i]){
        printf("! %d\n",i);
        ++cnt;
    }
    assert(cnt==1);
    return 0;
}