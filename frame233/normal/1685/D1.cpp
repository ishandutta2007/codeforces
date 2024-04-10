#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=205;
int a[N],b[N];bool vis[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),b[a[i]]=i,vis[i]=0;
	for(int i=1;i<=n;++i)if(!vis[i]){
		for(int u=i;!vis[u];u=a[u])vis[u]=1;
		if(i!=1)std::swap(b[i-1],b[i]);
	}
	for(int u=1,t=0;t<n;++t,u=b[u])printf("%d%c",u," \n"[t+1==n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}