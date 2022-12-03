#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500;

int n,a[N+9][N+9];
int cnt,num;

void Dfs_ans(int x,int y){
  a[x][y]=num;
  if (!--cnt) return;
  if (y>1&&!a[x][y-1]){
	Dfs_ans(x,y-1);
	if (!cnt) return;
  }
  if (x<n&&!a[x+1][y]){
	Dfs_ans(x+1,y);
	if (!cnt) return;
  }
}

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	int x;
	scanf("%d",&x);
	cnt=x;num=x;
	Dfs_ans(i,i);
  }
}

void work(){
}

void outo(){
  for (int i=1;i<=n;++i){
	for (int j=1;j<=i;++j)
	  printf("%d ",a[i][j]);
    puts("");
  }
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}