#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;

int n,x[N+9],y[N+9];

void into(){
  scanf("%d",&n);
  int cx=0,cy=0;
  for (int i=1;i<=n<<1;++i){
	int u,v;
	scanf("%d%d",&u,&v);
	u?x[++cx]=abs(u):y[++cy]=abs(v);
  }
}

double ans;

void work(){
  ans=0;
  sort(x+1,x+n+1);
  sort(y+1,y+n+1);
  for (int i=1;i<=n;++i) ans+=sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
}

void outo(){
  printf("%.15lf\n",ans);
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