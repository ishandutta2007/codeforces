#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int l[N+9],r[N+9];
int q[N*5+9],hd,tl,vis[N+9];
int ans[N+9],ca;

void Get_ans(){
  for (int i=1;i<=n;++i) vis[i]=0,l[i]=i==1?n:i-1,r[i]=i==n?1:i+1;
  hd=1;tl=ca=0;
  for (int i=1;i<=n;++i)
	if (__gcd(a[i],a[r[i]])==1) q[++tl]=i;
  for (;hd<=tl;){
	int t=q[hd];++hd;
	if (vis[t]||vis[r[t]]) continue;
	if (__gcd(a[t],a[r[t]])==1){
	  ans[++ca]=r[t];
	  if (t==r[t]) return;
	  int k=r[t];
	  r[l[k]]=r[k];l[r[k]]=l[k];vis[k]=1;
	  if (__gcd(a[t],a[r[t]])==1) q[++tl]=t;
	}
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d",ca);
  for (int i=1;i<=ca;++i)
	printf(" %d",ans[i]);
  puts("");
}

int main(){
  int T;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}