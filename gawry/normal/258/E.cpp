#include<cstdio>
#include<vector>
using namespace std;
#define MAX 110000
int n,m,pre[MAX],post[MAX],next,ans[MAX];
vector<int> s[MAX],a[MAX];
#define POWER (1<<17)
int add[2*POWER],smallest[2*POWER],cnt[2*POWER];
void dfs1(int x,int y=0){
  pre[x]=++next;
  smallest[POWER+next]=0;
  for(int i=0;i<s[x].size();i++)if(s[x][i]!=y)dfs1(s[x][i],x);
  post[x]=next;
}
void repair(int pos){
  if(pos>=POWER){
    smallest[pos]=add[pos];
    cnt[pos]=1;
    return;
  }
  smallest[pos]=min(smallest[2*pos],smallest[2*pos+1]);
  cnt[pos]=0;
  if(smallest[pos]==smallest[2*pos])cnt[pos]+=cnt[2*pos];
  if(smallest[pos]==smallest[2*pos+1])cnt[pos]+=cnt[2*pos+1];
  smallest[pos]+=add[pos];
}
void change(int from,int to,int delta){
//  printf("%d,%d %d\n",from,to,delta);
  from+=POWER;
  to+=POWER;
  add[from]+=delta;
  repair(from);
  if(from<to){
    add[to]+=delta;
    repair(to);
  }
  while(from+1<to){
    if(from%2==0){
      add[from+1]+=delta;
      repair(from+1);
    }
    if(to%2){
      add[to-1]+=delta;
      repair(to-1);
    }
    repair(from);
    repair(to);
    from/=2;
    to/=2;
  }
  while(from){
    repair(from);
    from/=2;
  }
  while(to){
    repair(to);
    to/=2;
  }
}
int get(int pos){
  pos+=POWER;
  int ans=0;
  while(pos){
    ans+=add[pos];
    pos/=2;
  }
  return ans;
}
void dfs2(int x,int y=0){
  for(int i=0;i<a[x].size();i++){
    change(pre[a[x][i]],post[a[x][i]],1);
    change(pre[x],post[x],1);
  }
  ans[x]=smallest[1]?n-1:n-cnt[1]-!!get(pre[x]);
  //printf("%d %d %d : %d\n",add[1],smallest[1],cnt[1],ans[x]);
  for(int i=0;i<s[x].size();i++)if(s[x][i]!=y)dfs2(s[x][i],x);
  for(int i=0;i<a[x].size();i++){
    change(pre[a[x][i]],post[a[x][i]],-1);
    change(pre[x],post[x],-1);
  }
  //printf("%d %d %d\n",add[1],smallest[1],cnt[1]);
}
main(){
  for(int i=POWER;i<2*POWER;i++){
    smallest[i]=1;
    cnt[i]=1;
  }
  scanf("%d %d",&n,&m);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  dfs1(1);
  for(int i=POWER-1;i;i--)repair(i);
  while(m--){
    int x,y;
    scanf("%d %d",&x,&y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs2(1);
  for(int i=1;i<=n;i++)printf("%d%c",ans[i],i<n?' ':'\n');
}