#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
bitset<2002>B[2002],A[2002];
char s[2002],v[2002];
int t,n,m,sz[2002],Qx[8000002],Qy[8000002],hd,tl,fa[2002],num,S[2002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),hd=1,tl=0;
		for(re int i=1;i<=n;++i)A[i].reset(),v[i]=0,fa[i]=0,S[i]=0;
		for(re int i=1;i<=m;++i){
			scanf("%s",s+1),B[i].reset();
			for(re int j=1;j<=n;++j)B[i][j]=s[j]-'0';
			sz[i]=B[i].count();
			if(sz[i]==1)--m,--i;
		}
		for(re int i=1;i<=m;++i)
			for(re int j=1;j<=n;++j)
				if(B[i][j])A[j][i]=1,++S[j];
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j)
				if(i!=j&&(A[i]&A[j]).count()==S[j])
					Qx[++tl]=j,Qy[tl]=i;num=0;
		while(hd<=tl&&num<n-1){
			re int x=Qx[hd],y=Qy[hd++];
			if(v[x]||v[y])continue;
			fa[x]=y,++num,v[x]=1;
			for(re int i=1;i<=m;++i)
				if(B[i][x]){
					B[i][x]=0,--sz[i];
					if(sz[i]==1){
						re int pos=B[i]._Find_first();
						A[pos][i]=0,--S[pos];
						for(re int j=1;j<=n;++j)if(j^pos&&(A[j]&A[pos]).count()==S[pos])Qx[++tl]=pos,Qy[tl]=j;
					}
				}
		}
		if(num<n-1){
			puts("NO");
			continue;
		}
		puts("YES");
		for(re int i=1;i<=n;++i)if(fa[i])printf("%d %d\n",i,fa[i]);
	}
}