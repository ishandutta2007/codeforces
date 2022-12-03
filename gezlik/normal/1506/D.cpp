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

map<int,int>mp;
int ans;

void Get_ans(){
  mp.clear();
  for (int i=1;i<=n;++i) ++mp[a[i]];
  for (auto [x,y]:mp)
	if (y>n>>1) {ans=y-(n-y);return;}
  ans=n&1;
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