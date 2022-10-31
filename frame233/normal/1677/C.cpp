#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=100005;
int a[N],b[N],p[N];bool vis[N];
int c[N],pos;
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]),p[a[i]]=b[i];
	memset(vis,0,n+3);
	long long ans=0;int l=1,r=n;
	for(int i=1;i<=n;++i)if(!vis[i]){
		int len=0;for(int u=i;!vis[u];u=p[u])vis[u]=1,++len;
		len-=len%2,pos=0;
		for(int j=0;j<len/2;++j)c[pos++]=l++,c[pos++]=r--;
		for(int j=0;j<pos;++j)ans+=abs(c[j]-c[j+1==pos?0:j+1]);
	}
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}