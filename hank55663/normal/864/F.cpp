#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> v[3005];
int p[3005][13];
int ok[3005];
int vis[3005];
int instk[3005];
vector<int> stk;
void dfs(int x,int len){
    stk.pb(x);
    ok[x]=len;
    //vis[x]=1;
    instk[x]=1;
    for(auto it:v[x]){
        if(instk[it]){
            vector<int> q;
            while(stk.size()){
                int x=stk.back();
                instk[x]=0;
                stk.pop_back();
                vis[x]=1;
                q.pb(x);
                if(x==it){
                    break;
                }
            }
            while(!q.empty()){
                int x=q.back();
                q.pop_back();
                for(auto it:v[x]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.pb(it);
                    }
                }
            }
        }
        else if(vis[it]||ok[it]){
        }
        else{
            p[it][0]=x;
            dfs(it,len+1);
        }
        if(stk.back()!=x){
            return;
        }
    }
    instk[x]=0;
    assert(stk.back()==x);
    stk.pop_back();
}//
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
    }
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    vector<pair<pii,int> > qq[3005];
    int ans[400005];
    for(int i = 0;i<q;i++){
        int s,t,k;
        scanf("%d %d %d",&s,&t,&k);
        qq[s].pb(mp(mp(t,k),i));
       // if(i==96){
        //    printf("%d %d %d\n",s,t,k);
        //}
    }
    for(int i = 1;i<=n;i++){
        fill(vis,vis+n+1,0);
        stk.clear();
        fill(instk,instk+n+1,0);
        fill(ok,ok+n+1,0);
        MEM(p);
        p[i][0]=i;
        dfs(i,1);
        for(int j=1;j<13;j++){
            for(int k=1;k<=n;k++){
                p[k][j]=p[p[k][j-1]][j-1];
            }
        }
        for(auto it:qq[i]){
            int s=i;
            int t=it.x.x;
            int k=it.x.y;
           /* if(it.y==96){
                printf("%d %d %d %d\n",s,t,k,ok[t]);
            }*/
            if(ok[t]<k){
                ans[it.y]=-1;
            }
            else{
                int need=ok[t]-k;
                int now=t;
                for(int j = 0;j<13;j++){
                    if(need&(1<<j)){
                        now=p[now][j];
                    }
                }
                ans[it.y]=now;
            }
        }
    }
    for(int i = 0;i<q;i++)
        printf("%d\n",ans[i]);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/