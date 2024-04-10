#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;
const LL INF=(1LL<<60)-1;

int n,a[N+9],b[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  for (int i=1;i<=n;++i)
	scanf("%d",&b[i]);
}

struct tree{
  LL max,add;
}tr[N*4+9];

void Pushup(int k){tr[k].max=max(tr[k<<1].max,tr[k<<1|1].max);}
void Update_add(int k,LL v){tr[k].max+=v;tr[k].add+=v;}

void Pushdown(int k){
  if (!tr[k].add) return;
  Update_add(k<<1,tr[k].add);
  Update_add(k<<1|1,tr[k].add);
  tr[k].add=0;
}

void Change_add(int L,int R,LL v,int l,int r,int k){
  if (L<=l&&R>=r) {Update_add(k,v);return;}
  int mid=l+r>>1;
  Pushdown(k);
  if (L<=mid) Change_add(L,R,v,l,mid,k<<1);
  if (R>mid) Change_add(L,R,v,mid+1,r,k<<1|1);
  Pushup(k);
}

LL Query_max(int L,int R,int l,int r,int k){
  if (L<=l&&R>=r) return tr[k].max;
  int mid=l+r>>1;
  LL res=-INF;
  Pushdown(k);
  if (L<=mid) res=max(res,Query_max(L,R,l,mid,k<<1));
  if (R>mid) res=max(res,Query_max(L,R,mid+1,r,k<<1|1));
  return res;
}

int sta[N+9],cst;
LL dp[N+9];

void Get_dp(){
  for (int i=1;i<=n;++i){
	Change_add(i-1,i-1,b[i],0,n,1);
	for (;cst&&a[sta[cst]]>=a[i];--cst)
	  Change_add(sta[cst-1],sta[cst]-1,b[i]-b[sta[cst]],0,n,1);
	sta[++cst]=i;
	dp[i]=Query_max(0,i-1,0,n,1);
	Change_add(i,i,dp[i],0,n,1);
  }
}

void work(){
  Get_dp();
}

void outo(){
  printf("%lld\n",dp[n]);
}

int main(){
  int T=1;
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}