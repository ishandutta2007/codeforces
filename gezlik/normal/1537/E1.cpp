#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000000;

int n,m;
char s[N+9];

void into(){
  scanf("%d%d%s",&n,&m,s+1);
  for (int i=1;i<=n;++i) s[i+n]=s[i];
  n<<=1;
}

int z[N+9];

void Ex_kmp(){
  z[1]=n;
  for (int i=2,l=0,r=0;i<=n;++i){
	if (i<=r) z[i]=min(r-i+1,z[i-l+1]);
	for (;i+z[i]<=n&&s[i+z[i]]==s[z[i]+1];++z[i]);
	if (i+z[i]-1>r) l=i,r=i+z[i]-1;
  }
}

char ans[N+9];

void Get_ans(){
  ans[1]=s[1];
  for (int i=2;i<=n&&i<=m;++i){
	if (i+z[i]<=n&&s[z[i]+1]<s[i+z[i]]){
	  for (int j=i;j<=m;++j) ans[j]=ans[j-i+1];
	  return;
	}
	ans[i]=s[i];
  }
  for (int j=n+1;j<=m;++j) ans[j]=ans[j-n];
}

void work(){
  Ex_kmp();
  Get_ans();
}

void outo(){
  for (int i=1;i<=m;++i)
	putchar(ans[i]);
  puts("");
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