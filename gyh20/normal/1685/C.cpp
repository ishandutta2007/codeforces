#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,A[200002],B[200002],t,pre[200002],suf[200002];
char s[200002];
inline bool ck(){
	re int o=0,ia=1;
	for(re int i=1;i<=n;++i)o+=s[i]=='('?1:-1,ia&=o>=0;
	return ia;
}
int main(){
	t=read();
	while(t--){
		n=read()<<1,scanf("%s",s+1),m=0;
		while(!ck()){
			for(re int i=1;i<=n;++i)pre[i]=pre[i-1]+(s[i]=='('?1:-1);suf[n+1]=0;
			for(re int i=n;i;--i)suf[i]=suf[i+1]+(s[i]==')'?1:-1);
			re int p1=0,p2=n+1,pos=0;
			for(re int i=1;i<=n;++i){
				if(pre[i]>pre[p1])p1=i;
				if(pre[i]<0)break;
			}
			for(re int i=1;i<=n;++i)if(pre[i]>pre[pos])pos=i;
			for(re int i=n;i;--i){
				if(suf[i]>suf[p2])p2=i;
				if(suf[i]<0)break;
			}
			++m,A[m]=p1+1,B[m]=p2-1;
			reverse(s+A[m],s+B[m]+1);
			if(!ck()){
				reverse(s+A[m],s+B[m]+1);
				reverse(s+A[m],s+pos+1);
				reverse(s+pos+1,s+B[m]+1);
				m=2;
				A[1]=p1+1,B[1]=pos;
				A[2]=pos+1,B[2]=p2-1;
				assert(ck());
			}
		}
		printf("%d\n",m);
		for(re int i=1;i<=m;++i)printf("%d %d\n",A[i],B[i]);
	}
}