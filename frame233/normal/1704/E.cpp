#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
std::vector<int> e[N];int a[N],b[N],f[N],_q[N],_l,_r,dg[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)dg[i]=0,e[i].clear();
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb(y),++dg[y];
	int ans=0;
	for(int i=1;i<=n;++i){
		bool flag=0;for(int i=1;i<=n;++i)flag|=a[i]!=0;
		if(!flag)break;
		memcpy(b,a,(n+3)<<2),++ans;
		for(int j=1;j<=n;++j)if(a[j]>0){
			--b[j];for(auto v:e[j])++b[v];
		}
		memcpy(a,b,(n+3)<<2);
	}
	_l=1,_r=0;for(int i=1;i<=n;++i)if(!dg[i])_q[++_r]=i;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(auto v:e[x])if(!--dg[v])_q[++_r]=v;
	}
	f[_q[n]]=1;add(ans,a[_q[n]]);
	for(int i=n-1;i>=1;--i){
		int x=_q[i];f[x]=0;
		for(auto v:e[x])add(f[x],f[v]);
		add(ans,1LL*a[x]*f[x]%mod);
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}