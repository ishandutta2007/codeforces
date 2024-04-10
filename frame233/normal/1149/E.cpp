#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],dg[N],_q[N],_l,_r,f[N],val[N];
std::vector<int> e[N],E[N],w[N];
bool vis[N];
int mex(const std::vector<int> &v){
	for(auto it:v)vis[it]=true;
	int ans=0;while(vis[ans])++ans;
	for(auto it:v)vis[it]=false;
	return ans;
}
int main(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[y].pb(x),++dg[x],E[x].pb(y);
	_l=1,_r=0;for(int i=1;i<=n;++i)if(!dg[i])_q[++_r]=i;
	while(_l!=_r+1){
		int x=_q[_l++];f[x]=mex(w[x]);
		for(auto v:e[x]){
			w[v].pb(f[x]);
			if(!--dg[v])_q[++_r]=v;
		}
	}
	for(int i=1;i<=n;++i)val[f[i]]^=a[i];
	bool flag=0;for(int i=0;i<=n;++i)flag|=val[i];
	if(!flag)return puts("LOSE"),0;
	puts("WIN");
	int p=-1;for(int i=n;i>=0;--i)if(val[i]){p=i;break;}
	for(int i=1;i<=n;++i)if(f[i]==p&&(val[p]^a[i])<a[i]){
		a[i]^=val[p];for(auto v:E[i])if(val[f[v]])a[v]^=val[f[v]],val[f[v]]=0;
		break;
	}
	for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}