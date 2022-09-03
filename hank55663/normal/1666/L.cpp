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
vector<int> v[200005];
int vis[200005];
int ans;
int dfs(int x,int s){
    if(vis[x]&&vis[x]!=s){
        ans=x;
        return vis[x];
    }
    vis[x]=s;
    for(auto it:v[x]){
        if(vis[it]){
            if(vis[it]!=s){
                ans=it;
                return vis[it];
            }
            continue;
        }
        int a=dfs(it,s);
        if(a)return a;
    }
    return 0;
}
bool go(int x,int t,vector<int> &vv){
    vv.pb(x);
    vis[x]=1;
    if(x==t)return true;
    for(auto it:v[x]){
        if(!vis[it]){
            if(go(it,t,vv))return true;
        }
    }vv.pop_back();
    return false;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
   // n=rand()%10+1;
    //m=rand()%10+1;
    int s;
    scanf("%d",&s);
   // s=rand()%n+1;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
     //   x=rand()%n+1;
       // y=rand()%n+1;
        if(y!=s)
        v[x].pb(y);
    }
    MEM(vis);
    for(auto it:v[s]){
        int x;
        if(x=dfs(it,it)){
            vector<int> v1,v2;
            MEM(vis);
            assert(go(x,ans,v1));
            MEM(vis);
            assert(go(it,ans,v2));
            MEM(vis);
            for(auto it:v2)vis[it]=1;
            vector<int> ans1,ans2;
            ans1.pb(s);
            ans2.pb(s);
            for(auto it:v1){
                ans1.pb(it);
                if(vis[it])break;
            }
            for(auto it:v2){
                ans2.pb(it);
                if(it==ans1.back())break;
            }
            printf("Possible\n");
            printf("%d\n",ans1.size());
            for(auto it:ans1)printf("%d ",it);
            printf("\n");
            printf("%d\n",ans2.size());
            for(auto it:ans2)printf("%d ",it);
            printf("\n");
            return;
        }
    }
    printf("Impossible\n");
}
int main(){
    int t=1;00000;
  //  scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/