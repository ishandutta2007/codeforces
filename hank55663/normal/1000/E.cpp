#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
vector<int> v[300005];
int vis[300005];
int t,lw[300005];
vector<int> stk;
vector<vector<int> > bcc;
pii p[300005];
int belong[300005];
void dfs(int a,int f){
    vis[a]=lw[a]=++t;
    for(auto it:v[a]){
        if(it!=f){
            if(!vis[it]){
                stk.pb(it);
                dfs(it,a);
                /*
                if(lw[it]>=vis[a]){
                    vector<int> res;
                    while(stk.back()!=it){
                        res.pb(stk.back());
                        belong[stk.back()]=bcc.size();
                        printf("%d %d\n",stk.back(),bcc.size());
                        stk.pop_back();
                    }
                    res.pb(stk.back());
                    belong[stk.back()]=bcc.size();
                    printf("%d %d\n",stk.back(),bcc.size());
                    stk.pop_back();
                    bcc.pb(res);
                }
                else{*/
                    lw[a]=min(lw[a],lw[it]);
            }
            else{
                lw[a]=min(lw[a],vis[it]);
            }
        }
    }
    vector<int> res;
    if(lw[a]==vis[a]){
        while(stk.back()!=a){
            res.pb(stk.back());
            belong[stk.back()]=bcc.size();
            //printf("%d %d\n",stk.back(),bcc.size());
            stk.pop_back();
        }
        res.pb(stk.back());
        belong[stk.back()]=bcc.size();
        //printf("%d %d\n",stk.back(),bcc.size());
        stk.pop_back();
         bcc.pb(res);
    }
}
set<int> bccv[300005];
int ans;
int dfs2(int a,int f){
    vector<int> vv;
    vv.pb(0);
    vv.pb(0);
    for(auto it:bccv[a]){
        if(it!=f){
            vv.pb(dfs2(it,a));
        }
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
   // printf("%d %d %d\n",a,vv[0],vv[1]);
    ans=max(ans,vv[0]+vv[1]);
    return vv[0]+1;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    ans=0;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    stk.pb(1);
    dfs(1,0);
    //printf("?\n");
    for(int i=1;i<=n;i++){
        for(auto it:v[i]){
            if(belong[it]!=belong[i]){
                bccv[belong[i]].insert(belong[it]);
           //     printf("%d %d\n",belong[i],belong[it]);
            }
        }
    }
    dfs2(0,-1);
    printf("%d\n",ans);
}