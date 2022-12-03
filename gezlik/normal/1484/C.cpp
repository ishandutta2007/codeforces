#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,m;
vector<int>a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=m;++i){
	int c;
	scanf("%d",&c);
	a[i].resize(c);
	for (int j=0;j<c;++j)
	  scanf("%d",&a[i][j]);
  }
}

int cnt[N+9];
int ans0,ans[N+9];

void Get_ans(){
  for (int i=1;i<=n;++i) cnt[i]=0;
  ans0=1;
  for (int i=1;i<=m;++i) ++cnt[ans[i]=a[i][0]];
  int t=0;
  for (int i=1;i<=n;++i)
	if (cnt[i]>m+1>>1) t=i;
  if (!t) return;
  for (int i=1;i<=m;++i)
	if (a[i][0]==t&&a[i].size()>1&&cnt[t]>m+1>>1) --cnt[t],ans[i]=a[i][1];
  if (cnt[t]>m+1>>1) ans0=0;
}

void work(){
  Get_ans();
}

void outo(){
  if (ans0){
	puts("YES");
	for (int i=1;i<=m;++i)
	  printf("%d ",ans[i]);
    puts("");
  }else puts("NO");
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