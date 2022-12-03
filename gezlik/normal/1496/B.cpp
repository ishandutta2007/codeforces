#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;

int n,m,a,b;
map<int,bool>vis;

void into(){
  scanf("%d%d",&n,&m);
  vis.clear();
  a=b=0;
  for (int i=1;i<=n;++i){
	int x;
	scanf("%d",&x);
	vis[x]=1;
    a=max(a,x);
  }
}

void work(){
  for (;vis[b];++b);
  if (b>a) {printf("%d\n",n+m);return;}
  for (int i=1;i<=m;++i){
	int now=a+b+1>>1;
	if (vis[now]) {printf("%d\n",n+i-1);return;}
	vis[now]=1;
	for (;vis[b];++b);
    if (b>a) {printf("%d\n",n+m);return;}
  }
  printf("%d\n",n+m);
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