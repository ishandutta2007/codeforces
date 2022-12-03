#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000;

int n,m,a[N+9];
char s[N+9];

void into(){
  scanf("%d%d%s",&n,&m,s+1);++m;
  for (int i=1;i<=n;++i) a[i]=s[i]-'0';
}

int dis[N+9];
queue<int>q;

void Bfs_dis(){
  for (int i=1;i<=n;++i) dis[i]=0;
  for (int i=1;i<=n;++i)
	if (a[i]) dis[i]=1,q.push(i);
  for (;!q.empty();){
	int i=q.front();q.pop();
	if (i>1&&!dis[i-1]) dis[i-1]=dis[i]+1,q.push(i-1);
	if (i<n&&!dis[i+1]) dis[i+1]=dis[i]+1,q.push(i+1);
  }
}

void work(){
  Bfs_dis();
}

void outo(){
  for (int i=1;i<=n;++i) putchar(dis[i]==1||dis[i]&&dis[i-1]^dis[i+1]&&dis[i]<=m?'1':'0');
  puts("");
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