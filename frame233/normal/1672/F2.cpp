#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],b[N],c[N];std::vector<int> e[N];int _q[N],_l,_r,dg[N];
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)e[i].clear(),dg[i]=0,c[i]=0;
	for(int i=1;i<=n;++i)read(a[i]),++c[a[i]];
	for(int i=1;i<=n;++i)read(b[i]);
	int mx=std::max_element(c+1,c+n+1)-c;
	for(int i=1;i<=n;++i)if(a[i]!=mx&&b[i]!=mx)e[a[i]].pb(b[i]),++dg[b[i]];
	_l=1,_r=0;for(int i=1;i<=n;++i)if(!dg[i])_q[++_r]=i;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(auto v:e[x])if(!--dg[v])_q[++_r]=v;
	}
	puts(_r==n?"AC":"WA");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}