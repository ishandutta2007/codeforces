#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100;

int n,m,a[N+9];

bool Check(int n){
  int t=sqrt(n);
  if (t*t==n) return 1;
  return 0;
}

void into(){
  scanf("%d",&n);
  if (n&1) puts("NO");
  else{
	n>>=1;
	if (Check(n)) puts("YES");
	else if (n&1^1&&Check(n>>1)) puts("YES");
	  else puts("NO");
  }
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