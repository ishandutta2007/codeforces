#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000000,INF=(1<<30)-1;

int n,m;
struct state{
  int x,y;
  state(int X=0,int Y=0){x=X;y=Y;}
}a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
    scanf("%d%d",&a[i].x,&a[i].y);
  sort(a+1,a+n+1,[&](const state &a,const state &b){return a.y<b.y;});
  a[0].y=m;
}

int c[N+9];
 
void Add(int p,int v){for (;p;p-=p&-p) c[p]+=v;}
int Query(int p){int res=0;for (;p<=n;p+=p&-p) res+=c[p];return res;}
 
struct tree{
  int max,add;
}tr[N*4+9];
 
void Pushup(int k){tr[k].max=max(tr[k<<1].max,tr[k<<1|1].max);}
void Update_add(int v,int k){tr[k].max+=v;tr[k].add+=v;}
 
void Pushdown(int k){
  if (!tr[k].add) return;
  Update_add(tr[k].add,k<<1);
  Update_add(tr[k].add,k<<1|1);
  tr[k].add=0;
}
 
void Build(int l,int r,int k){
  tr[k].add=0;
  if (l==r) {tr[k].max=l;return;}
  int mid=l+r>>1;
  Build(l,mid,k<<1);
  Build(mid+1,r,k<<1|1);
  Pushup(k);
}

void Change(int p,int v,int l,int r,int k){
  if (l==r) {tr[k].max=v;return;}
  int mid=l+r>>1;
  Pushdown(k);
  p<=mid?Change(p,v,l,mid,k<<1):Change(p,v,mid+1,r,k<<1|1);
  Pushup(k);
}
 
void Change_add(int L,int R,int v,int l,int r,int k){
  if (L<=l&&R>=r) {Update_add(v,k);return;}
  int mid=l+r>>1;
  Pushdown(k);
  if (L<=mid) Change_add(L,R,v,l,mid,k<<1);
  if (R>mid) Change_add(L,R,v,mid+1,r,k<<1|1);
  Pushup(k);
}
 
int Query_max(int L,int R,int l,int r,int k){
  if (L>R) return -INF;
  if (L<=l&&R>=r) return tr[k].max;
  int mid=l+r>>1,res=-INF;
  Pushdown(k);
  if (L<=mid) res=max(res,Query_max(L,R,l,mid,k<<1));
  if (R>mid) res=max(res,Query_max(L,R,mid+1,r,k<<1|1));
  return res;
}

int st;

void Get_st(){
  for (int i=n;i>=1;--i)
    if (a[i].y<=m) {st=i;break;}
}

int tmp[N+9],dp[N+9];

void Get_ans(){
  vector<int>gg;
  for (int i=st+1;i<=n;++i){
    gg.push_back(i);
    Add(i,1);
  }
  for (int i=0;i<=n;++i) tmp[i]=max(a[i].y,m);
  sort(gg.begin(),gg.end(),[&](const int &i,const int &j){return a[i].x<a[j].x;});
  for (int i=1;i<=st;++i) dp[st]+=a[i].x>=m;
  Change(st,dp[st]+n-st,0,n,1);
  for (int i=st+1,j=0;i<=n;++i){
    for (;j<gg.size()&&a[gg[j]].x<a[i].y;++j){
      Change_add(st,gg[j]-1,-1,0,n,1);
      Add(gg[j],-1);
    }
    int pos=min((int)(upper_bound(tmp,tmp+n+1,a[i].x)-tmp),i);
    dp[i]=Query_max(st,pos-1,0,n,1)+1;
    dp[i]=max(dp[i],Query_max(pos,i-1,0,n,1));
    dp[i]-=Query(i);
    Change(i,dp[i]+Query(i+1),0,n,1);
  }
}

void work(){
  Get_st();
  Get_ans();
}

void outo(){
  printf("%d\n",dp[n]);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}