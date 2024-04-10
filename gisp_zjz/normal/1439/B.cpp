#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=123456;
typedef long long ll;
typedef pair<int,int>pi;
int _,n,m,k,d[maxn];
bool vis[maxn];
vector<int> G[maxn];
queue<int> q1,q2;
unordered_map<ll,int> S;
void del(int u){
    for (auto v:G[u]){
        d[v]--;
        if (d[v]<k-1) q1.push(v);
        else if (d[v]==k-1) q2.push(v);
    }
}
bool check(int u){
    if (k>10000||k*(k-1)/2>m) return 0;
    vector<int> vc; vc.clear();
    for (auto v:G[u]) if (!vis[v]) vc.pb(v);
    if (vc.size()!=k-1) return 0;
    sort(vc.begin(),vc.end());
    for (int i=0;i<k-1;i++)
    for (int j=i+1;j<k-1;j++){
        int u=vc[i],v=vc[j];
        if (S.find((ll)u*n+v)==S.end()) return 0;
    }
    puts("2");
    printf("%d",u);
    for (auto x:vc) printf(" %d",x);puts("");
    return 1;
}
int main(){
    cin >> _;
    while (_--){
        scanf("%d%d%d",&n,&m,&k); S.clear();
        for (int i=1;i<=n;i++) d[i]=0,vis[i]=0,G[i].clear();
        for (int i=1;i<=m;i++){
            int u,v;scanf("%d%d",&u,&v);
            if (u>v) swap(u,v);
            S[(ll)u*n+v]=1;
            d[u]++; d[v]++;
            G[u].pb(v); G[v].pb(u);
        }
        for (int i=1;i<=n;i++) {
            if (d[i]<k-1) q1.push(i);
            else if (d[i]==k-1) q2.push(i);
        }
        int tot=0;
        bool flag=0;
        while (!q1.empty()||!q2.empty()){
            if (!q1.empty()){
                int u=q1.front(); q1.pop();
                if (vis[u]) continue;
                vis[u]=1; del(u); tot++;
            } else if (!q2.empty()){
                int u=q2.front(); q2.pop();
                if (vis[u]) continue;
                if (check(u)){
                    flag=1;
                } else {
                    vis[u]=1; del(u); tot++;
                }
            }
            if (flag) break;
        }
        //cout<<tot<<endl;
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
        if (flag) continue;
        if (tot==n) puts("-1");
        else {
            vector<int> ans; ans.clear();
            for (int i=1;i<=n;i++) if (!vis[i]) ans.pb(i);
            printf("1 %d\n",ans.size());
            for (auto x:ans) printf("%d ",x);puts("");
        }
    }
    return 0;
}