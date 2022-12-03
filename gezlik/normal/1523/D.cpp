#include<bits/stdc++.h>
using namespace std;

mt19937 Rand(time(0));

typedef long long LL;

const int N=200000,M=60,K=15;

void FMT(int *a,int n){
  for (int i=1;i<n;i<<=1)
	for (int j=0;j<n;j+=i<<1)
	  for (int k=0;k<i;++k) a[j+k]+=a[i+j+k];
}

int n,m,sk,a[N+9][M+9];

void into(){
  scanf("%d%d%d",&n,&m,&sk);
  static char s[M+9];
  for (int i=1;i<=n;++i){
	scanf("%s",s);
	for (int j=0;j<m;++j) a[i][j]=s[j]-'0';
  }
}

int pos[M+9],cp;
int cnt[(1<<K)+9];
int ans[M+9],ans0;

void Get_ans(){
  int p=Rand()%n+1;
  cp=0;
  for (int j=0;j<m;++j)
	if (a[p][j]) pos[cp++]=j;
  for (int s=0;s<1<<cp;++s) cnt[s]=0;
  for (int i=1;i<=n;++i){
	int s=0;
	for (int j=0;j<cp;++j) s|=a[i][pos[j]]<<j;
	++cnt[s];
  }
  FMT(cnt,1<<cp);
  for (int s=0;s<1<<cp;++s){
    if (cnt[s]<n+1>>1) continue;
	int now=__builtin_popcount(s);
	if (now<=ans0) continue;
	ans0=now;
	for (int i=0;i<m;++i) ans[i]=0;
	for (int i=0;i<cp;++i) ans[pos[i]]=s>>i&1;
  }
}

void work(){
  for (int i=1;i<=20;++i) Get_ans();
}

void outo(){
  for (int i=0;i<m;++i)
	putchar(ans[i]+'0');
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