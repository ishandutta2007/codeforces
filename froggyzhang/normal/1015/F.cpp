#include<bits/stdc++.h>
using namespace std;
#define N 204
const int mod=1e9+7;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,nxt[N],to[N][2],dp[N][N][N];
char s[N];
int main(){
	n=read()<<1;
	scanf("%s",s+1);
	m=strlen(s+1);
	for(int i=2,j=0;i<=m;++i){
		while(j&&s[i]^s[j+1])j=nxt[j];
		j+=s[i]==s[j+1];
		nxt[i]=j;
	}
	to[m][0]=to[m][1]=m;
	for(int i=0;i<m;++i){
		for(int p=0;p<=1;++p){
			char c=p?'(':')';
			if(s[i+1]==c)to[i][p]=i+1;
			else to[i][p]=to[nxt[i]][p];
		}
	}
	dp[0][0][0]=1;
	#define update(x,y) x=(x+y)%mod
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			for(int k=0;k<=m;++k){
				int w=dp[i-1][j][k];
				if(!w)continue;
				for(int p=0;p<=1;++p){
					int tj=j+(p?1:-1);
					if(tj>=0)update(dp[i][tj][to[k][p]],w);
				}
			}
		}
	}
	printf("%d\n",dp[n][0][m]);
	return 0;
}