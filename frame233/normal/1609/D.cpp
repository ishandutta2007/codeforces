#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;
int fa[N],siz[N],a[N],pos;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n,d;read(n,d);
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	int cnt=0;
	for(int i=1,x,y;i<=d;++i){
		read(x,y),x=find(x),y=find(y);
		if(x==y)++cnt;
		else fa[x]=y,siz[y]+=siz[x];
		int ans=0;pos=0;for(int j=1;j<=n;++j)if(fa[j]==j)a[++pos]=siz[j];
		std::sort(a+1,a+pos+1,std::greater<int>());
		for(int i=1;i<=cnt+1&&i<=pos;++i)ans+=a[i];
		printf("%d\n",ans-1);
	}
	return 0;
}