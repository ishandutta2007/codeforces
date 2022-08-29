#include<bits/stdc++.h>
#define re register
#define M 998244353
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],t,l,r,ans[1000002],cnt,c[1000002];
char s[100002];
signed main(){
	t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);l=r=cnt=0;
		for(re int i=1;i<=n;++i)a[i]=s[i]-'0',c[i]=0;
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i)b[i]=s[i]-'0';
		for(re int i=2;i<=n;++i){
			if(a[i]!=a[i-1])ans[++cnt]=i-1;
		}l=a[n];
		for(re int i=n;i;--i){
			if(l!=b[i])ans[++cnt]=i,l^=1;
		}
		printf("%d ",cnt);
		for(re int i=1;i<=cnt;++i)printf("%d ",ans[i]);
		puts("");
	}
}