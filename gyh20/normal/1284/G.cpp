#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int A[805],B[805],pre[805],S,T,n,m,fa[805],dis[805],Q[805],hd,tl,d[805],col[805],k;
char vis[805],usd[805],inq[805],G[805][805],s[22][22],ans[805][805];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	x=root(x),y=root(y);
	if(x==y)++vis[x];
	else fa[x]=y,vis[y]+=vis[x];
}
inline bool ck1(){
	for(re int i=1;i<=n;++i)fa[i]=i,vis[i]=0;
	for(re int i=1;i<=m;++i)
		if(usd[i]){
			Merge(A[i],B[i]);
			if(vis[root(A[i])])return 0;
		}
	return 1;
}
inline bool ck2(){
	for(re int i=1;i<=n;++i)d[i]=col[i]?(col[i]-1):-114514;
	for(re int i=1;i<=m;++i)
		if(usd[i]){
			++d[A[i]],++d[B[i]];
			if(d[A[i]]>2||d[B[i]]>2)return 0;
		}
	return 1;
}
int main(){
	int t=read();
	while(t--){
		n=read(),k=read(),m=0;
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		int tt=0,nn=0;memset(usd,0,sizeof(usd));
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=k;++j){
				col[++tt]=(i+j+1)&1;
				if(s[i][j]=='X')col[tt]=0;
				if(col[tt])nn+=s[i][j]=='O';
				if(s[i][j]=='O'&&s[i][j+1]=='O'&&j!=k)A[++m]=(i-1)*k+j,B[m]=(i-1)*k+j+1;
				if(s[i][j]=='O'&&s[i+1][j]=='O'&&i!=n)A[++m]=(i-1)*k+j,B[m]=i*k+j;
			}
		col[1]=2,S=m+1,T=m+2,n*=k,--nn;
		while(1){
			for(re int i=1;i<=T;++i)dis[i]=0;dis[S]=1;
			for(re int i=1;i<=T;++i)for(re int j=1;j<=T;++j)G[i][j]=0;
			int nn=0;
			for(re int i=1;i<=m;++i)
				if(!usd[i]){
					usd[i]=1;
					if(ck1())G[S][i]=1;
					if(ck2())G[i][T]=1;
					usd[i]=0;
				}else ++nn;
			for(re int i=1;i<=m;++i)
				if(usd[i]){
					usd[i]=0;
					ck1();
					for(re int j=1;j<=m;++j)
						if((i^j)&&(!usd[j])){
							re int x=root(A[j]),y=root(B[j]);
							if(x^y)G[i][j]=1;
						}
					ck2();
					for(re int j=1;j<=m;++j)	
						if((i^j)&&(!usd[j]))
							if(d[A[j]]+1<=2&&d[B[j]]+1<=2)G[j][i]=1;
					usd[i]=1;
				}
			Q[hd=tl=1]=S;
			while(hd<=tl){
				re int x=Q[hd++];
				for(re int i=1;i<=T;++i)if(G[x][i]&&!dis[i])dis[i]=dis[x]+1,pre[i]=x,Q[++tl]=i;
			}
			if(!dis[T])break;
			re int x=T;
			while(x^S)usd[x]^=1,x=pre[x];
		}
		for(re int i=1;i<=n;++i)fa[i]=i;re int ss=0;
		for(re int i=1;i<=m;++i)if(usd[i])Merge(A[i],B[i]),++ss;
		ck2();
		re bool ia=1;
		for(re int i=2;i<=n;++i)if(col[i])ia&=d[i]==2;
		if(!ia){
			puts("NO");
			continue;
		}
		for(re int i=1;i<=m;++i)if(root(A[i])^root(B[i]))usd[i]=1,Merge(A[i],B[i]);
		n/=k;
		for(re int i=1;i<=n+n;++i)
			for(re int j=1;j<=k+k;++j)
				ans[i][j]=' ';
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=k;++j)
				ans[i*2-1][j*2-1]=s[i][j];
		for(re int i=1;i<=m;++i)
			if(usd[i]){
				re int px=(A[i]-1)/k+1,py=(A[i]-1)%k+1;
				if(B[i]==A[i]+1)ans[px*2-1][py*2]='O';
				else ans[px*2][py*2-1]='O';
			}
		puts("YES");
		for(re int i=1;i<=n+n-1;++i,puts(""))
			for(re int j=1;j<=k+k-1;++j)
				putchar(ans[i][j]);
	}
}