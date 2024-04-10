#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,mx,ans;
char s[200002];
int v[200002][27];
signed main(){
	t=read();
	while(t--){
		n=read();m=read();
		scanf("%s",s+1);ans=0;
		for(re int j=1;j<=m;++j){
		mx=0;
		for(re int i=j;i<=n;i+=m){
			++v[min(j,m-j+1)][s[i]-'a'];//putchar(s[i]);
		}}
		for(re int j=1;j<=(m+1)/2;++j){
			mx=0;
			for(re int i=0;i<26;++i)mx=max(mx,v[j][i]);
			ans+=mx;
			memset(v[j],0,sizeof(v[j]));
		}
		printf("%d\n",n-ans);
	}
}