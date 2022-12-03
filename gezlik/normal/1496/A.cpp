#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=10000;

int n,m;
char s[N+9];

void into(){
  scanf("%d%d%s",&n,&m,s+1);
}

void work(){
  int cnt=0;
  for (int i=1;i<=n-1>>1;++i)
	if (s[i]^s[n-i+1]) break;
    else ++cnt;
  puts(cnt>=m?"YES":"NO");
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