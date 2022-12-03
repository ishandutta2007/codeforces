#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=2000000,INF=(1<<30)-1;

int n,m,a[N+9],b[N+9],ord[N+9],co;

void into(){
  scanf("%d%d",&n,&m);
  co=0;
  for (int i=1;i<=n;++i){
    scanf("%d",&a[i]);
    ord[++co]=a[i];
  }
  for (int i=1;i<=m;++i){
    scanf("%d",&b[i]);
    ord[++co]=b[i];
  }
}

void Get_ord(){
  sort(ord+1,ord+co+1);
  co=unique(ord+1,ord+co+1)-ord-1;
  for (int i=1;i<=n;++i) a[i]=lower_bound(ord+1,ord+co+1,a[i])-ord;
  for (int i=1;i<=m;++i) b[i]=lower_bound(ord+1,ord+co+1,b[i])-ord;
}

int c[N+9];

void Add(int p,int v){for (;p<=co;p+=p&-p) c[p]+=v;}
int Query(int p){int res=0;for (;p;p-=p&-p) res+=c[p];return res;}
int Query(int l,int r){return Query(r)-Query(l-1);}

struct tree{
  int min,add;
}tr[N*4+9];

void Pushup(int k){
  tr[k].min=min(tr[k<<1].min,tr[k<<1|1].min);
}

void Update_add(int v,int k){tr[k].min+=v;tr[k].add+=v;}

void Pushdown(int k){
  if (!tr[k].add) return;
  Update_add(tr[k].add,k<<1);
  Update_add(tr[k].add,k<<1|1);
  tr[k].add=0;
}

void Build(int l,int r,int k){
  tr[k].add=0;
  if (l==r) {tr[k].min=l;return;}
  int mid=l+r>>1;
  Build(l,mid,k<<1);
  Build(mid+1,r,k<<1|1);
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

int Query_min(int L,int R,int l,int r,int k){
  if (L<=l&&R>=r) return tr[k].min;
  int mid=l+r>>1,res=INF;
  Pushdown(k);
  if (L<=mid) res=min(res,Query_min(L,R,l,mid,k<<1));
  if (R>mid) res=min(res,Query_min(L,R,mid+1,r,k<<1|1));
  return res;
}

int tmp[N+9],d[N+9];
LL ans;

void Get_ans(){
  ans=0;
  for (int i=1;i<=co;++i) c[i]=0;
  for (int i=1;i<=n;++i){
    ans+=Query(a[i]+1,co);
    Add(a[i],1);
  }
  for (int i=1;i<=co;++i) tmp[i]=0;
  for (int i=1;i<=m;++i) ++tmp[b[i]];
  for (int i=1,j=1;i<=co;++i)
    for (;tmp[i];--tmp[i]) b[j++]=i;
  for (int i=1;i<=co;++i) tmp[i]=0;
  for (int i=1;i<=n;++i) ++tmp[a[i]];
  for (int i=1;i<=co;++i) tmp[i]+=tmp[i-1];
  for (int i=1;i<=n;++i) d[tmp[a[i]]--]=i;
  Build(0,n,1);
  for (int i=1,j=1,k=1;i<=m;++i){
    for (;j<=n&&a[d[j]]<=b[i];++j) Change_add(d[j],n,-1,0,n,1);
    for (;k<=n&&a[d[k]]<b[i];++k) Change_add(0,d[k]-1,1,0,n,1);
    ans+=Query_min(0,n,0,n,1);
  }
}

void work(){
  Get_ord();
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}