#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=2000000;

int n,a[N+9];
char s[N+9];

void into(){
  scanf("%d%s",&n,s+1);
  for (int i=1;i<=n;++i) a[i]=a[i+n]=s[i]-'a'+1;
}

void work(){
}

void Get_ans(int m,int x){
  int res=m;
  for (int l=1,r=1,now=0;r<=n;++r){
	now+=a[r]!=x;
	for (;l<=r&&now>m;++l) now-=a[l]!=x;
	res=max(res,r-l+1);
  }
  printf("%d\n",min(res,n));
}

void outo(){
  int cq;
  scanf("%d",&cq);
  for (;cq--;){
	int m,x;
	char tmp[3];
	scanf("%d%s",&m,tmp);
	Get_ans(m,tmp[0]-'a'+1);
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