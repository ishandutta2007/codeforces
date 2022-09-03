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
#define index Index
#define MXN 1000000
vector<pii> v[600005];
int vis[600005];
int vise[600005];
vector<vector<pii> > res;
int cnt=0;
int dfs(int x,int f,int ff){
   // printf("st %d\n",x);
    vector<pii> vv;
    vis[x]=1;
    for(auto it:v[x]){
        if(it.y!=f){
            
            cnt++;
            if(vis[it.x]){
                if(!vise[it.y])
                vv.pb(mp(x,it.x));
                vise[it.y]=1;
            }      
            else{
                vise[it.y]=1;
                if(dfs(it.x,it.y,x)){
                    vv.pb(mp(x,it.x));
                }
            }
        }
    }
  //  printf("?%d %d %d\n",x,vv.size());
  //printf("%d\n",x);
    //for(auto it:vv){
      //  printf("%d %d\n",it.x,it.y);
  //  }
    while(vv.size()>1){
        auto p1=vv.back();
        vv.pop_back();
        auto p2=vv.back();
        vv.pop_back();
        res.pb({p1,p2});
    }
    if(vv.size()==1){
        if(f){
            res.pb({vv.back(),mp(x,ff)});
            return 0;
        }
        if(cnt==1)return 0;
        res.back().pb(vv.back());
        return 0;
    }
    else{
    //    printf("ret\n");
        return 1;
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(y,i));
        if(x!=y)
        v[y].pb(mp(x,i));
    }
    for(int i = 1;i<=2*n;i++){
        if(!vis[i]){
            dfs(i,0,0);
            if(cnt==1){
                printf("-1\n");
                return;
            }
            cnt=0;
        }
    }
    int ans[2][300005];
    char a[2][300005],b[2][300005];
    MEM(a);
    MEM(b);
    int now=0;
    for(auto it:res){
        if(it.size()==2){
            assert(it[0].x==it[1].x);
            ans[0][now]=ans[1][now+1]=it[0].x;
            ans[0][now+1]=it[0].y;
            ans[1][now]=it[1].y;
            a[0][now]=a[1][now]='L';
            a[0][now+1]=a[1][now+1]='R';
            b[0][now]=b[0][now+1]='U';
            b[1][now]=b[1][now+1]='D';
            now+=2;
        }
        else{
            int ok=0;
            for(int t = 0;t<2;t++){
                if(it[1].y==it[0].x)swap(it[1].x,it[1].y);
                if(it[2].y==it[0].x)swap(it[2].x,it[2].y);
                if(it[0].x==it[1].x&&it[0].x==it[2].x){
                    //printf("!!");
                    ans[0][now]=ans[1][now+1]=ans[0][now+2]=it[0].x;
                    ans[1][now]=it[0].y;
                    ans[0][now+1]=it[1].y;
                    ans[1][now+2]=it[2].y;
                    a[0][now]=a[1][now]='L';
                    a[0][now+1]=a[1][now+1]='R';
                    a[0][now+2]='U';
                    a[1][now+2]='D';
                    b[0][now+1]=b[1][now+1]='L';
                    b[0][now+2]=b[1][now+2]='R';
                    b[0][now]='U';
                    b[1][now]='D';
                    ok=1;
                    break;
                }
                swap(it[0].x,it[0].y);
            }
            if(!ok){
                for(int t=0;t<3;t++){
                    if(it[1].y==it[0].x)swap(it[1].y,it[1].x);
                    if(it[1].x==it[0].y)swap(it[1].y,it[1].x);
                    if(it[2].x==it[0].y)swap(it[2].x,it[2].y);
                    if(it[2].y==it[0].x)swap(it[2].x,it[2].y);
                   // printf("%d %d)(%d %d)(%d %d\n",it[0].x,it[0].y,it[1].x,it[1].y,it[2].x,it[2].y);
                    if(it[1].x==it[0].x&&it[0].y==it[2].y){
                        ans[0][now+1]=it[0].x;
                        ans[1][now+1]=it[0].y;
                        ans[0][now]=it[1].y;
                        ans[1][now]=it[1].x;
                        ans[0][now+2]=it[2].y;
                        ans[1][now+2]=it[2].x;
                        a[0][now]=a[1][now]='L';
                        a[0][now+1]=a[1][now+1]='R';
                        a[0][now+2]='U';
                        a[1][now+2]='D';
                        b[0][now+1]=b[1][now+1]='L';
                        b[0][now+2]=b[1][now+2]='R';
                        b[0][now]='U';
                        b[1][now]='D';
                        ok=1;
                        break;
                    }
                    else if(it[1].y==it[0].y&&it[0].x==it[2].x){
                        ans[0][now+1]=it[0].x;
                        ans[1][now+1]=it[0].y;
                        ans[0][now]=it[2].y;
                        ans[1][now]=it[2].x;
                        ans[0][now+2]=it[1].y;
                        ans[1][now+2]=it[1].x;
                        a[0][now]=a[1][now]='L';
                        a[0][now+1]=a[1][now+1]='R';
                        a[0][now+2]='U';
                        a[1][now+2]='D';
                        b[0][now+1]=b[1][now+1]='L';
                        b[0][now+2]=b[1][now+2]='R';
                        b[0][now]='U';
                        b[1][now]='D';
                        ok=1;
                        break;
                    }
                    if(t!=2){
                        swap(it[0],it[t+1]);
                    }
                }
            }
            assert(ok);
            now+=3;
        }
    }
    printf("2 %d\n\n",n);
    for(int i = 0;i<2;i++){
        for(int j = 0;j<now;j++)printf("%d ",ans[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("%s\n%s\n\n%s\n%s\n",a[0],a[1],b[0],b[1]);
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}