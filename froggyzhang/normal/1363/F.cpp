#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020 
inline int read(){
	int x=0,f=1;
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
int T,cnta[26],cntb[26],n,dp[N][N];
char a[N],b[N];
int main(){
	T=read();
	while(T--){
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;++i){
			++cnta[a[i]-'a'];
		}
		for(int i=1;i<=n;++i){
			++cntb[b[i]-'a'];
		}
		bool ok=true;
		for(int i=0;i<26;++i){
			if(cnta[i]^cntb[i]){
				ok=false;
				printf("-1\n");
				break;
			}
		}
		if(!ok)continue;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j]=0;
			}
		}
		memset(cnta,0,sizeof(cnta));
		int pos=0;
		for(int i=1;i<=n;++i){
			--cnta[a[i]-'a'];
			while(cnta[a[i]-'a']<0){
				++cnta[b[++pos]-'a'];
			}
			int now=n+1;
			for(int j=pos;j<=n;++j){
				now=min(now,dp[i-1][j]+1);
				dp[i][j]=now;
				if(j<n&&a[i]==b[j]){
					now=min(now,dp[i-1][j]);
				}
			}
		}
		printf("%d\n",dp[n][n]-1);
		
	}
	return 0;
}