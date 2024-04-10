#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,A,B,C,D,p1[200002],p2[200002],n1,n2,na,nb,n3,p3[200002];
char s[200002];
int main(){
//	freopen("a.out","w",stdout);
	t=read();
	while(t--){
		A=read(),B=read(),C=read(),D=read();
		scanf("%s",s+1),n1=n2=n3=na=nb=0,n=strlen(s+1);
		for(re int i=1;i<=n;++i)if(s[i]=='A')++na;else ++nb;
		if(A+C+D!=na||B+C+D!=nb){
			puts("NO");
			continue;
		}
		for(re int l=1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&s[r+1]!=s[r])++r;
			if((r-l)&1){
				if(s[l]=='A')p3[++n3]=r-l+1>>1;
				else p2[++n2]=r-l+1>>1;
			}
			else p1[++n1]=r-l>>1;
		}
		re int num=0;sort(p3+1,p3+n3+1);
		for(re int i=1;i<=n1;++i)num+=p1[i];
		for(re int i=1;i<=n2;++i)num+=p2[i];
		for(re int i=1;i<=n3;++i)num+=p3[i]-1;
		if(C){
			for(re int i=1;i<=n3&&C;++i){
				re int o=min(p3[i],C);
				C-=o,num-=min(p3[i]-1,o);
			}
		}
		if(C){
			for(re int i=1;i<=n1&&C;++i){
				re int o=min(p1[i],C);
				C-=o,num-=o;
			}
		}
		sort(p2+1,p2+n2+1),reverse(p2+1,p2+n2+1);
		if(C){
			for(re int i=1;i<=n2&&C;++i){
				re int o=min(p2[i]-1,C);
				C-=o,num-=o+1;
			}
		}
		puts(C==0&&num>=D?"YES":"NO");
	}
}