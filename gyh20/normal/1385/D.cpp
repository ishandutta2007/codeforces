#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[200002],ans,b[200002][27],k,len,dp[22][200002],xx;;
char s[200002];
int main(){
	t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i)a[i]=s[i]-'a'+1;
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=26;++j)b[i][j]=b[i-1][j];
			++b[i][a[i]];
		}
		k=n;while(k)++len,k>>=1;
		for(re int i=0;(1<<i)<=n;++i){xx=i;
			for(re int j=1;j<=n;j+=(1<<i)){
				if(i==0)dp[i][j]=(a[j]!=len);
				else{
					dp[i][j]=min(dp[i-1][j]+((1<<i-1)-(b[j+(1<<(i))-1][len]-b[j+(1<<(i-1))-1][len])),dp[i-1][j+(1<<i-1)]+((1<<i-1)-(b[j+(1<<i-1)-1][len]-b[j-1][len])));
				}
			}
			--len;
		}
		printf("%d\n",dp[xx][1]);
	}
}