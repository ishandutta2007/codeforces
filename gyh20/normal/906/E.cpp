#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,tot,ch[1000002][26],f[1000002],pre[1000002],fa[1000002],len[1000002],lst;
char a[500002],b[500002],s[1000002];
inline int find(re int x,re int y){
	while(s[x]!=s[x-len[y]-1])y=fa[y];
	return y;
}
inline void ins(re int x){
	re int y=find(x,lst);
	if(!ch[y][s[x]-'a'])++tot,len[tot]=len[y]+2,fa[tot]=ch[find(x,fa[y])][s[x]-'a'],ch[y][s[x]-'a']=tot;
	lst=ch[y][s[x]-'a'];
}
int main(){
	scanf("%s%s",a+1,b+1),m=strlen(a+1),lst=1,len[1]=-1,fa[0]=1,tot=1;
	for(re int i=1;i<=m;++i)s[++n]=a[i],s[++n]=b[i];
	for(re int i=1;i<=n;++i){
		ins(i);
		if(!(i&1)){
			f[i]=1145141;
			if(s[i]==s[i-1])f[i]=f[i-2],pre[i]=i-2;
			for(re int j=lst;j;j=fa[j])if(!(len[j]&1))if(f[i-len[j]]+1<f[i])f[i]=f[i-len[j]]+1,pre[i]=i-len[j];
		}
	}
	if(f[n]>n)return puts("-1"),0;
	printf("%d\n",f[n]);
	re int x=n;
	while(x){
		if(pre[x]^(x-2))printf("%d %d\n",pre[x]/2+1,x/2);
		x=pre[x];
	}
}