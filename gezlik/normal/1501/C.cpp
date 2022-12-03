#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000,M=5000000;

int n,a[N+9];
struct state{
  int x,y;
  state(int X=0,int Y=0){x=X;y=Y;}
}b[M+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

void Get_ans(){
  for (int i=1;i<=n;++i)
	for (int j=i+1;j<=n;++j){
      int t=a[i]+a[j];
	  if (!b[t].x) {b[t]=state(i,j);continue;}
	  if (i==b[t].x||j==b[t].x||i==b[t].y||j==b[t].y) continue;
	  puts("YES");
	  printf("%d %d %d %d\n",i,j,b[t].x,b[t].y);
	  return;
	}
  puts("NO");
}

void work(){
  Get_ans();
}

void outo(){
}

int main(){
  into();
  work();
  outo();
  return 0;
}