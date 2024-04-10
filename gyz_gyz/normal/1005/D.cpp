#include<cstdio>
#include<map>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000000
#define inf 1000000000
using namespace std;
char s[N];
int f[N][3],a[N],n,ans;
int main(){
	for(scanf("%s",s);s[n];n++)a[n+1]=(s[n]-'0')%3;
	rep(i,1,n)rep(j,0,2)f[i][j]=-inf;f[1][a[1]]=(a[1]==0);
	rep(i,2,n){
		rep(j,0,2)f[i][a[i]]=max(f[i][a[i]],f[i-1][j]+(a[i]==0));
		rep(j,0,2)f[i][j]=max(f[i][j],f[i-1][(j+3-a[i])%3]+(j==0));
	}
	rep(i,0,2)ans=max(ans,f[n][i]);
	printf("%d\n",ans);
}