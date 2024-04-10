#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,d[1002],Q[1002],hd,tl,B,ia,zt,vis[1<<20];
char g[1002][1002];
vector<int>A,b,C;
inline void ins(re int x,re int y,re int z){A.push_back(x),b.push_back(y),C.push_back(z);}
inline void ck0(re int x,re int z){
	if(ia)return;
	if(!vis[z])vis[z]=x,ia=1;
}
inline void ck1(re int x,re int z){
	if(ia)return;
	for(re int i=0;i<B;++i)if(!vis[z^(1<<i)]){ia=1,vis[z^(1<<i)]=x,ins(g[x][Q[i+n-B+1]]?'-':'+',x,Q[i+n-B+1]);return;}
}
inline void ck2(re int x,re int z){
	if(ia)return;
	for(re int i=0;i<B;++i)
		for(re int j=0;j<B;++j)
			if(!vis[z^(1<<i)^(1<<j)]){
				ia=1,vis[z^(1<<i)^(1<<j)]=x;
				ins(g[x][Q[i+n-B+1]]?'-':'+',x,Q[i+n-B+1]);
				ins(g[x][Q[j+n-B+1]]?'-':'+',x,Q[j+n-B+1]);
				return;
			}
}
inline void ck3(re int x,re int z){
	if(ia)return;
	for(re int i=0;i<B;++i)
		for(re int j=0;j<B;++j)
			for(re int k=0;k<B;++k)
				if(!vis[z^(1<<i)^(1<<j)^(1<<k)]){
					ia=1,vis[z^(1<<i)^(1<<j)^(1<<k)]=x;
					ins(g[x][Q[i+n-B+1]]?'-':'+',x,Q[i+n-B+1]);
					ins(g[x][Q[j+n-B+1]]?'-':'+',x,Q[j+n-B+1]);
					ins(g[x][Q[k+n-B+1]]?'-':'+',x,Q[k+n-B+1]);
					return;
				}
} 
inline void solve(){
	zt=0;
	for(re int i=n-B+1;i<=n;++i){
		printf("? 1 %d\n",Q[i]);fflush(stdout);
		char s[12];
		scanf("%s",s+1);
		if(s[1]=='L'){
			printf("! %d\n",Q[i]),fflush(stdout),scanf("%s",s+1);
			return;
		}
		if(s[1]=='W')zt|=1<<i-(n-B+1);
	}
	char s[12];
	printf("! %d\n",vis[zt]),fflush(stdout);scanf("%s",s+1);
}
int main(){
	n=read(),m=read();int t=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),g[x][y]=1,++d[y];
	for(re int i=hd=1;i<=n;++i)if(!d[i])Q[++tl]=i;
	while(hd<=tl){
		re int x=Q[hd++];
		for(re int i=1;i<=n;++i)if(g[x][i]&&(!--d[i]))Q[++tl]=i;
	}B=min(n,20);
	for(re int i=1;i<=n-B;++i)ins('+',Q[i],Q[i]);
	for(re int i=n-B+1;i<=n;++i)for(re int j=i+1;j<=n;++j)if(!g[Q[i]][Q[j]])ins('+',Q[i],Q[j]);
	for(re int i=n-B;i;--i){
		re int z=0;
		for(re int j=n-B+1;j<=n;++j)if(g[Q[i]][Q[j]])z|=1<<j-(n-B+1);
		ia=0,ck0(Q[i],z),ck1(Q[i],z),ck2(Q[i],z),ck3(Q[i],z);
	}
	printf("%u\n",A.size());
	for(re int i=0;i<A.size();++i)printf("%c %d %d\n",A[i],b[i],C[i]);fflush(stdout);
	while(t--)solve();
}