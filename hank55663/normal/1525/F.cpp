#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
vector<int> v[55];
int match[55];
int vis[55];
int vis2[55];
int degree[55];
bool dfs(int x){
    if(vis[x])return false;
    vis[x]=1;
    for(auto it:v[x]){
        vis2[it]=1;
        if(match[it]==-1||dfs(match[it])){
            match[it]=x;
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        degree[y]++;
    }
    fill(match,match+n+1,-1);
    int ans=0;
    vector<int> tmp;
    for(int i = 1;i<=n;i++){
        MEM(vis);
        if(dfs(i)){
            ans++;
        }
        else{
            tmp.pb(i);
        }
    }
    MEM(vis);
    MEM(vis2);
    for(auto it:tmp)dfs(it);
    vector<int> res;
    for(int i = 1;i<=n;i++){
        if(!vis[i]&&v[i].size())res.pb(i);
        if(vis2[i]&&degree[i])res.pb(-i);
    }
    int x[55],y[55];
    ans=n-ans;
    for(int i = 1;i<=k;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    LL best=-1;
    vector<vector<int>> output;
    for(int i = 1;i<=k;i++){
        int now=0;
        LL tot=0;
        LL Min=1e9,Mini=1;
        vector<vector<int> > rec(k+1);
        for(int j = 1;j<i;j++){
            tot+=x[j];
            if(y[j]<Min){
                Min=y[j];
                Mini=j;
                //Min=min(Min,1e9);
            }
            if(j>=ans){
                rec[Mini].pb(res[now++]);
                tot-=Min;
            }
        }
        while(now!=res.size()){
            rec[i].pb(res[now++]);
        }
        for(int j = i+1;j<=k;j++)tot+=x[j];
        if(tot>best){
            best=tot;
            output=rec;
        }
      //  printf("%lld\n",tot);
    }
        LL cnt=0;
   // printf("%d\n",cnt);
    int fi=1;
   /* for(auto it:output){
        for(auto it2:it){
            printf("%d ",it2);
        }
        if(fi)fi=0;
        else
        printf("0 ");
    }
    printf("\n");*/
    int now=0;
    LL tot=0;
    LL Min=1e9,Mini=1;
    vector<vector<int> > rec(k+1);
    for(int j = 1;j<=k;j++){
         tot+=x[j];
        if(y[j]<Min){
            Min=y[j];
            Mini=j;
            //Min=min(Min,1e9);
        }
        if(j>=ans){
            rec[Mini].pb(res[now++]);
            tot-=Min;
        }
    }
    if(tot>best){
        best=tot;
        output=rec;
    }
    // printf("%lld\n",tot);
    for(auto it:output){
        for(auto it2:it){
            cnt++;
        }
        cnt++;
    }
    printf("%d\n",cnt-1);
    fi=1;
    for(auto it:output){
        for(auto it2:it){
            printf("%d ",it2);
        }
           if(fi)fi=0;
        else
        printf("0 ");
    }
    printf("\n");
}
int main(){
    int t=1;
 //   scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
a b
b a
b a a
a a b
a a b b
a b b a
a b b a a
a b a a b
a b a b a

*/