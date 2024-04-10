#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,x,y,a[N+9];

void into(){
  scanf("%d%d%d",&n,&x,&y);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  //if (x<y) reverse(a+1,a+n+1),swap(x,y);
}

int cnt[N+9][2],ans;

void work(){
  for (int i=1;i<=n;++i) cnt[i][0]=cnt[i][1]=0;
  for (int i=1;i<=x;++i) ++cnt[a[i]][0];
  for (int i=x+1;i<=n;++i) ++cnt[a[i]][1];
  x=0;y=0;
  for (int i=1;i<=n;++i){
	int t=min(cnt[i][0],cnt[i][1]);
	cnt[i][0]-=t;cnt[i][1]-=t;
	x+=cnt[i][0];y+=cnt[i][1];
  }
  if (x<y){
	for (int i=1;i<=n;++i) swap(cnt[i][0],cnt[i][1]);
	swap(x,y);
  }
  ans=x+y>>1;
  x=x-y>>1;
  for (int i=1;i<=n;++i) x-=cnt[i][0]>>1;
  ans+=max(x,0);
}

void outo(){
  printf("%d\n",ans);
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