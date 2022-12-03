#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100;

int n,a[N+9],b[N+9],tim[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d%d",&a[i],&b[i]);
  for (int i=1;i<=n;++i)
	scanf("%d",&tim[i]);
}

int ans;

void Get_ans(){
  ans=0;
  for (int i=1;i<=n;++i){
	ans+=a[i]-b[i-1]+tim[i];
	if (i==n) break;
	ans+=b[i]-a[i]+1>>1;
	ans=max(ans,b[i]);
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
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