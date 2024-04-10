#include<bits/stdc++.h>
using namespace std;

const int N=100000,C=21;

int n,cq,last[N+9],nxt[N+9][C];

void Get(int id){
  int x;
  scanf("%d",&x);
  int t=x;
  for (int i=2;i*i<=x;++i){
	if (t%i) continue;
	for (;t%i==0;t/=i);
	int p=last[i];
	if (p) nxt[p][0]=min(nxt[p][0],id);
	last[i]=id;
  }
  if (t==1) return;
  int p=last[t];
  if (p) nxt[p][0]=min(nxt[p][0],id);
  last[t]=id;
}

void into(){
  scanf("%d%d",&n,&cq);
  for (int i=1;i<=n+1;++i) nxt[i][0]=n+1;
  for (int i=1;i<=n;++i) Get(i);
}

void Get_nxt(){
  for (int i=n;i>=1;--i) nxt[i][0]=min(nxt[i][0],nxt[i+1][0]);
  for (int i=1;i<C;++i){
	nxt[n+1][i]=n+1;
	for (int j=1;j<=n;++j) nxt[j][i]=nxt[nxt[j][i-1]][i-1];
  }
}

void work(){
  Get_nxt();
}

void outo(){
  for (;cq--;){
	int l,r,ans=0;
	scanf("%d%d",&l,&r);
	for (int i=C-1;i>=0;--i)
	  if (nxt[l][i]<=r) ans+=1<<i,l=nxt[l][i];
	printf("%d\n",ans+1);
  }
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