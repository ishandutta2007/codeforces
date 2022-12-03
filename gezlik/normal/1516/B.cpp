#include<bits/stdc++.h>
using namespace std;

const int N=100000;

int n,a[N+9],xr;

void into(){
  scanf("%d",&n);
  xr=0;
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	xr^=a[i];
  }
}

int ans;

void Get_ans(){
  ans=0;
  if (!xr){
	ans=1;
	return;
  }
  int p0=-1,p1=-1;
  for (int i=1,now=0;i<=n;++i)
	if ((now^=a[i])==xr) {p0=i;break;}
  for (int i=n,now=0;i>=1;--i)
	if ((now^=a[i])==xr) {p1=i;break;}
  if (p0==-1||p1==-1) return;
  if (p0<p1-1) ans=1;
}

void work(){
  Get_ans();
}

void outo(){
  puts(ans?"YES":"NO");
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