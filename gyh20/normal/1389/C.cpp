#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
using namespace std;
int n,m,vis[26],ans,t,w;
char s[200002];
inline int calc(re int x,re int y){
	re int pos=1,xx=0;
	while(1){
	while(s[pos]!=x+'0'&&pos<=n)++pos;++pos;
	while(s[pos]!=y+'0'&&pos<=n)++pos;
	if(pos>n)break;++pos;
	xx+=2;
	}
	return n-xx;
}
int main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);memset(vis,0,sizeof(vis));
		for(re int i=1;i<=n;++i)++vis[s[i]-'0'];
		w=0;for(re int i=0;i<=9;++i)w=max(w,vis[i]);
		ans=n-w;
		for(re int i=0;i<=9;++i)for(re int j=0;j<=9;++j)ans=min(ans,calc(i,j));
		printf("%d\n",ans);
	}
}