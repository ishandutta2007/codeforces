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
queue<char>q;
int main(){
	t=read();
	p['>']=2,p['<']=1;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		re int ans=0;
		while(!q.empty())q.pop();
		for(re int i=1;i<=n;++i){
			if(q.empty())q.push(s[i]);
			else if(s[i]=='A')q.push(s[i]);
			else q.pop(),ans+=2; 
		}
		printf("%d\n",n-ans);
	}
}