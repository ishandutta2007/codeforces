




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
#define rank Rank
#define KK 500
#define N 100005
#define MXN 2000005
vector<pii> v[300005];
int dep[300005];
void dfs(int x,int f){

    for(auto& it:v[x]){
        if(it.y!=f){
            dfs(it.y,x);
            it.x=dep[it.y];
        }    
        else{
            it.x=0;
        }
    }
    sort(v[x].begin(),v[x].end());
    reverse(v[x].begin(),v[x].end());
 //   printf("%d\n",x);
  //  for(auto it:v[x]){
   //     printf("%d %d ",it.x,it.y);
  //  }
  //  printf("\n");
    if(f!=0&&v[x].size()==1)
    dep[x]=0;
    else
    dep[x]=v[x][0].x+1;
   // printf("%d\n",dep[x]);
}
void dfs2(int x,int f,int Max){
    dep[x]=max(dep[x],Max);
    for(auto& it:v[x]){
        if(it.y!=f){
            if(it.y==v[x][0].y){
                if(v[x].size()!=1){
                    dfs2(it.y,x,max(Max,v[x][1].x+1)+1);
                }
                else{
                    dfs2(it.y,x,Max+1);
                }
            }
            else{
                dfs2(it.y,x,max(Max,v[x][0].x+1)+1);
            }
        }
    }
}
vector<int> res;
int ok=1;
void dfs3(int x,int f){
    if(v[x].size()==2&&f!=0)res.pb(x);
    if(v[x].size()==4){
        res.pb(x);
        if(v[x][1].x!=dep[x]-2||v[x][2].x!=dep[x]-2){
          //  printf("%d %d %d %d?\n",x,v[x][1].y,v[x][1].x,dep[x]);
            ok=0;
        }
    }
    if(v[x].size()==3){
        if(v[x][0].x!=v[x][1].x){
            ok=0;
            //printf("!\n");
        }
    }
    for(auto it:v[x]){
        if(it.y!=f){
            dfs3(it.y,x);
        }
    }
}
int root[100005];
int main(){
    int n;
    scanf("%d",&n);
    if(n==2){
        printf("2\n1 2\n");
        return 0;
    }
    for(int i = 0;i<(1<<n)-3;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(0,y));
        v[y].pb(mp(0,x));
    }
    dfs(1,0);
 //   for(int i = 1;i<=(1<<n)-2;i++)
 //       printf("%d ",dep[i]);
 //   printf("\n");
    dfs2(1,0,0);
    vector<int> tmp;
    for(int i = 1;i<=(1<<n)-2;i++){
        if(dep[i]==n-1)
        root[i]=1,tmp.pb(i);
     //   printf("%d ",dep[i]);
    }
    if(tmp.size()==1){
        dfs(tmp[0],0);
        dfs3(tmp[0],0);
        if(!ok){
            printf("0\n\n");
            return 0;
        }
        if(res.size()!=1){
            printf("0\n\n");
            return 0;
        }
        printf("1\n%d\n",res[0]);
    }
    else if(tmp.size()==2){
        for(int i = 1;i<=(1<<n)-2;i++){
            if(v[i].size()!=1&&v[i].size()!=3){
                printf("0\n\n");
                return 0;
            }
        }
        printf("2\n");
        printf("%d %d\n",tmp[0],tmp[1]);
    }
    else{
        printf("0\n\n");
    }
    return 0;
}