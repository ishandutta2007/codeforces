#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
vector<int> v[200005];
vector<pii> res[200005];
pii dfs(int x,int f){
  //  printf("%d\n",x);
    for(auto it:v[x]){
        if(it!=f){
            pii p=dfs(it,x);
            res[x].pb(p);
        }
    }
    if(res[x].empty()){
        res[x].pb(mp(0,x));
    }
    sort(res[x].begin(),res[x].end());
    reverse(res[x].begin(),res[x].end());
    //printf("%d\n",x);
    return mp(res[x][0].x+1,res[x][0].y);
}
void dfs2(int x,int f,pii p){
    if(f!=0)
    res[x].pb(p);
   // printf("%d\n",x);
    for(auto it:v[x]){
        if(it!=f){
            if(res[it][0].y==res[x][0].y){
                pii pp=p;
                if(res[x].size()>1){
                    pp=max(pp,res[x][1]);
                }
                pp.x++;
                dfs2(it,x,pp);
            }
            else{
                pii pp=max(p,res[x][0]);
                pp.x++;
                dfs2(it,x,pp);
            }
        }
    }
   // printf("%d\n",x);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
   // printf("?\n");
    dfs2(1,0,mp(0,1));
    //printf("?\n");
    vector<int> vv;
    int ans=0;
    for(int i = 1;i<=n;i++){
        sort(res[i].begin(),res[i].end());
        reverse(res[i].begin(),res[i].end());
        if(res[i].size()>=2){
            if(res[i].size()==2){
                if(res[i].back().x!=0){
                int tot=res[i][0].x+res[i][1].x;
                //printf("%d %d %d %d\n",i,tot,res[i].back().x,res[i].back().y);
                if(tot>ans){
                    ans=tot;
                    vv.pb(res[i][0].y);
                    vv.pb(res[i][1].y);
                    vv.pb(i);
                }
                }
            }
            else{
                int tot=res[i][0].x+res[i][1].x+res[i][2].x;
              //  for(auto it:res[i])
              //      printf("%d %d\n",it.x,it.y);
             //   printf("?%d %d %d %d\n",i,tot,res[i].back().x,res[i].back().y);
                if(tot>ans){
                    ans=tot;
                    vv.clear();
                    for(int j=0;j<3;j++)
                        vv.pb(res[i][j].y);
                }
            }
        }
    }
    printf("%d\n",ans);
    for(auto it:vv)
    printf("%d ",it);
    printf("\n");
}