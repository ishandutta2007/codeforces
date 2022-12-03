#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100;

int n,m,a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  int sum=0;
  for (int i=1;i<=n;++i){
	sum+=a[i];
	if (sum==m){
	  if (i==n) {puts("NO");return;}
	  swap(a[i],a[n]);
	  break;
	}
  }
  puts("YES");
  for (int i=1;i<=n;++i)
	printf("%d ",a[i]);
  puts("");
}

void work(){
}

void outo(){
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