#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=105;
int nxt[N],pre[N],p[N];
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i){
		printf("? ");for(int j=1;j<=n;++j)printf("%d ",1+(i==j));
		printf("\n"),fflush(stdout);
		int x;read(x);
		if(x!=i&&x)nxt[i]=x,pre[x]=i;
		printf("? ");for(int j=1;j<=n;++j)printf("%d ",2-(i==j));
		printf("\n"),fflush(stdout);
		read(x);
		if(x!=i&&x)nxt[x]=i,pre[i]=x;
	}
	for(int i=1;i<=n;++i)if(!pre[i]){
		int c=0;for(int u=i;u;u=nxt[u])p[u]=++c;
		printf("! ");
		for(int i=1;i<=n;++i)printf("%d%c",p[i]," \n"[i==n]);
		fflush(stdout);
		return 0;
	}
	return 0;
}