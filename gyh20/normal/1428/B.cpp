#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[1002],b,c,d,p[1002];
char s[300002];
inline int check(re int x){
	if(s[x]=='-')return 1;
	if(s[x]=='<'&&(!a[p['>']]))return 1;
	if(s[x]=='>'&&(!a[p['<']]))return 1;
	return 0;
}
int main(){
	t=read();
	p['>']=2,p['<']=1;
	while(t--){
		n=read();
		scanf("%s",s+1);
		s[0]=s[n];
		memset(a,0,sizeof(a));
		for(re int i=1;i<=n;++i)++a[p[s[i]]];
		re int ans=0;
		for(re int i=1;i<=n;++i)if(check(i)||check(i-1))++ans;
		printf("%d\n",ans);
	}
}