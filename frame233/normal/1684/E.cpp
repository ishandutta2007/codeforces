#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,NC=(1<<18)+5;
int a[N],b[N],f[NC],M,g[NC];
void build(int n){
	for(M=1;M<=n+2;M<<=1);
	memset(f,0,(M*2+3)<<2),memset(g,0,(M*2+3)<<2);
	for(int i=1;i<=n;++i)f[i+M]=i*b[i],g[i+M]=b[i];
	for(int i=M-1;i>=1;--i)f[i]=f[i<<1]+f[i<<1|1],g[i]=g[i<<1]+g[i<<1|1];
}
void upd(int x){f[x+M]-=x,--g[x+M];for(x=(x+M)>>1;x;x>>=1)f[x]=f[x<<1]+f[x<<1|1],g[x]=g[x<<1]+g[x<<1|1];}
int search(int k){
	int u=1,tot=0,ans=0;
	while(u<M){
		int tmp=tot+f[u<<1];
		if(tmp<=k)tot=tmp,ans+=g[u<<1],u=u<<1|1;
		else u<<=1;
	}
	if(u!=M)ans+=std::min(g[u],(k-tot)/(u-M));
	return ans;
}
void MAIN(){
	int n,k;read(n,k);memset(b,0,(n+3)<<2);
	std::map<int,int> mp;
	for(int i=1;i<=n;++i)read(a[i]),++mp[a[i]];
	for(const auto &it:mp)++b[it.second];
	int dif=SZ(mp);
	build(n);int cnt=0,ans=1e9;
	for(int m=0;m<=n;++m){ // [0,m)
		if(cnt>k)break;
		int tmp=search(k);ans=std::min(ans,dif+cnt-tmp-m);
		if(!mp.count(m))++cnt;else upd(mp[m]);
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}