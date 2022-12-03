#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=50;

int n,m;
char s[N+9];

void into(){
  scanf("%d%d%s",&n,&m,s+1);
}

int dp[N+9],ans;

void Get_ans(){
  int l,r;
  for (int i=1;i<=n;++i)
	if (s[i]=='*') {l=i;break;}
  for (int i=n;i>=1;--i)
	if (s[i]=='*') {r=i;break;}
  if (l==r) {ans=1;return;}
  dp[l]=1;
  for (int i=l+1;i<=r;++i){
	dp[i]=n+3;
	if (s[i]=='.') continue;
	for (int j=max(l,i-m);j<i;++j) dp[i]=min(dp[i],dp[j]+1);
  }
  ans=dp[r];
}

void work(){
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