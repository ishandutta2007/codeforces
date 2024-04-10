#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;
#define N 255
typedef unsigned long long ull;
int w[N][N],n,m,ln,lm,ans;
char str[N][N];
int b[N][26];
map<int,int>c;
int s1[N][N];
ull val[N],s2[N][N][26];
bool check(int x,int l,int r) {
	return c.count(s1[x][r]^s1[x][l-1]);
}
bool check2(int x,int y,int l,int r) {
	int i;
	for(i=0;i<26;i++) {
		if(s2[x][r][i]-s2[x][l-1][i]!=s2[y][r][i]-s2[y][l-1][i]) return 0;
	}
	return 1;
}
int rp[N<<1];
bool ck(int x) {return x&1;}
void kuo(int l,int r) {
	memset(rp,0,sizeof(rp));
	int i,mx=1,lst=1;
	ln=n*2+1;
	int re=0;
	for(i=1;i<=ln;i++) {
		rp[i]=min(mx-i,rp[2*lst-i]);
		if(rp[i]<=0) rp[i]=0;
		for(;ck(i-rp[i])||(i-rp[i]>=1&&i+rp[i]<=ln&&check2((i-rp[i])/2,(i+rp[i])/2,l,r)&&check((i-rp[i])/2,l,r)&&check((i+rp[i])/2,l,r));rp[i]++) ;
		re+=rp[i]/2;
		if(i+rp[i]-1>mx) {
			mx=i+rp[i]-1, lst=i;
		}
	}
	ans+=re;
}
int main() {
	srand(13123);
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=0;i<26;i++) {
		val[i]=rand()*(1ll<<45)+rand()*(1ll<<30)+rand()*(1<<15)+rand();
	}
	c[0]=1;
	for(i=0;i<26;i++) c[(1<<i)]=1;
	for(i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) w[i][j]=str[i][j]-'a';
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			s1[i][j]=s1[i][j-1]^(1<<w[i][j]);
			memcpy(s2[i][j],s2[i][j-1],sizeof(s2[i][j-1]));
			s2[i][j][w[i][j]]++;
		}
	}
	for(i=1;i<=m;i++) {
		for(j=i;j<=m;j++) {
			kuo(i,j);
		}
	}
	printf("%d\n",ans);
}