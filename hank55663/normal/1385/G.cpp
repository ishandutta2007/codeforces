#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int vis[200005];
int a[2][200005];
vector<pii> v[200005];
vector<int> stk,stk2;
int s;
int vis2[200005];
void dfs(int x,int f){
    if(x==s)return;
    vis2[x]=1;
    int cnt=0;
    for(auto it:v[x]){
        if(it.y!=f){
            if(it.y>0){
                stk.pb(it.y);
            }
            dfs(it.x,-it.y);
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    fill(vis,vis+n+1,0);
    fill(vis2,vis2+n+1,0);
    for(int i = 0;i<2;i++){
        for(int j =1;j<=n;j++){
            scanf("%d",&a[i][j]);
            vis[a[i][j]]++;
            v[j].clear();
        }
    }
    for(int i =1;i<=n;i++){
        if(vis[i]!=2){
            printf("-1\n");
            return;
        }
    }
    for(int i = 1;i<=n;i++){
       // printf("%d %d %d\n",a[0][i],a[1][i],i);
        v[a[0][i]].pb(mp(a[1][i],-i));
        v[a[1][i]].pb(mp(a[0][i],i));
    }
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(!vis2[i]){
            s=i;
            if(v[i][0].y>0)stk.pb(v[i][0].y);
            dfs(v[i][0].x,-v[i][0].y);
            vis2[i]=1;
            swap(stk,stk2);
            if(v[i][1].y>0)stk.pb(v[i][1].y);
            dfs(v[i][1].x,-v[i][1].y);
            if(stk.size()>stk2.size())swap(stk,stk2);
            for(auto it:stk)ans.pb(it);
            stk.clear();
            stk2.clear();
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}