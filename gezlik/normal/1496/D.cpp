#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int up[2][N+9],dn[2][N+9];
int l[N+9],r[N+9];

void Get_gg(){
  up[0][1]=dn[0][1]=1;
  for (int i=2;i<=n;++i){
	up[0][i]=a[i-1]>a[i]?up[0][i-1]+1:1;
	dn[0][i]=a[i-1]<a[i]?dn[0][i-1]+1:1;
  }
  up[1][n]=dn[1][n]=1;
  for (int i=n-1;i>=1;--i){
	up[1][i]=a[i+1]>a[i]?up[1][i+1]+1:1;
	dn[1][i]=a[i+1]<a[i]?dn[1][i+1]+1:1;
  }
  for (int i=1;i<=n;++i)
	l[i]=max(l[i-1],max(up[0][i],up[1][i]));
  for (int i=n;i>=1;--i)
	r[i]=max(r[i+1],max(up[0][i],up[1][i]));
}

int ans;

void Get_ans(){
  for (int i=2;i<n;++i){
	if (a[i-1]>a[i]||a[i+1]>a[i]) continue;
	if (up[0][i-1]>=dn[1][i]) continue;
	if (up[1][i+1]>=dn[0][i]) continue;
	if (dn[0][i]!=dn[1][i]) continue;
	int t=max(dn[0][i],dn[1][i]);
	if (l[i-dn[0][i]]>=t) continue;
	if (r[i+dn[1][i]]>=t) continue;
	if (up[0][i-dn[0][i]+1]>=t) continue;
	if (up[1][i+dn[1][i]-1]>=t) continue;
	if (dn[0][i]&1^1) continue;
	++ans;
  }
}

void work(){
  Get_gg();
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}