#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000,mod=998244353;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=0;i<n;++i)
	scanf("%d",&a[i]);
}

LL pre[3][N+9];

void Get_pre(){
  for (int i=1;i<=n;++i){
	pre[0][i]=pre[0][i-1]+a[i];
	pre[1][i]=pre[1][i-1]+(i&1?a[i]:0);
	pre[2][i]=pre[2][i-1]+(i&1?0:a[i]);
  }
}

int ans;

void Get_ans(int st,int x,int y){
  ans=(ans+(!(x&&y)&&st+pre[0][n]>0))%mod;
  for (int i=1;i<=n-y;++i){
	int l=1,r=i+1,pos=0,t=1+(i&1);
	for (int mid;l<=r;(mid=l+r>>1,st+pre[0][n]+2LL*(pre[t][i]-pre[t][mid-1]-pre[0][i])>0)?(pos=mid,l=mid+1):r=mid-1);
	ans=(ans+(pos+1)/2)%mod;
	if (pos>=1&&x&&i&1^1) ans=(ans+mod-1)%mod;
  }
}

void Get_ans(){
  for (int i=0;i<=n;++i)
	ans+=pre[0][i]+a[0]>pre[0][n]-pre[0][i]+a[n+1];
  ans%=mod;
}

void work(){
  ans=0;
  if (n==1) {ans=1;return;}
  n-=2;
  Get_pre();
  Get_ans(a[0]-a[n+1],1,1);
  Get_ans(a[0]+a[n+1],1,0);
  Get_ans(-a[0]+a[n+1],0,0);
  Get_ans(-a[0]-a[n+1],0,1);
  Get_ans();
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