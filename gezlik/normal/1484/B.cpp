#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n;
LL a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%lld",&a[i]);
}

void Get_ans(){
  if (n==1||n==2) {puts("0");return;}
  int flag=1;
  for (int i=2;i<=n;++i)
	if (a[i-1]>a[i]) {flag=0;break;}
  if (flag){
	for (int i=3;i<=n;++i)
	  if (a[i]-a[i-1]^a[i-1]-a[i-2]) {puts("-1");return;}
    puts("0");
	return;
  }
  flag=1;
  for (int i=3;i<=n;++i)
	if (a[i]-a[i-1]^a[i-1]-a[i-2]) {flag=0;break;}
  if (flag) {puts("0");return;}
  flag=1;
  for (int i=2;i<=n;++i)
    if (a[i-1]<a[i]) {flag=0;break;}
  if (flag) {puts("-1");return;}
  for (int i=2;i<=n;++i)
	if (a[i]==a[i-1]) {puts("-1");return;}
  LL c,m;
  int x,y;
  for (int i=2;i<=n;++i)
	if (a[i-1]<a[i]) x=i-1;
    else y=i-1;
  c=a[x+1]-a[x];
  m=a[y]+c-a[y+1];
  if (m<=0||c<0||c>=m) {puts("-1");return;}
  for (int i=1;i<=n;++i)
	if (a[i]>m) {puts("-1");return;}
  for (int i=2;i<=n;++i)
	if ((a[i-1]+c)%m^a[i]) {puts("-1");return;}
  printf("%lld %lld\n",m,c);
}

void work(){
  Get_ans();
}

void outo(){
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