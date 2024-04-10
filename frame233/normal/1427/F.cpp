#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1205;
int col[N],st[N],top,a[N],b[N],c[N],id,Fa[N],dg[N],bel[N],V[N];
std::vector<int> q[2];
int main(){
	int n;read(n);
	for(int i=1,x;i<=3*n;++i)read(x),col[x]=1;
	for(int i=1;i<=6*n;++i){
		if(top>=2&&col[st[top]]==col[st[top-1]]&&col[st[top]]==col[i])++id,a[id]=st[top-1],b[id]=st[top],c[id]=i,top-=2,Fa[id]=st[top],V[id]=col[i];
		else st[++top]=i;
	}
	for(int i=1;i<=id;++i)bel[a[i]]=bel[b[i]]=bel[c[i]]=i;
	for(int i=1;i<=id;++i)Fa[i]=bel[Fa[i]],++dg[Fa[i]];
	for(int i=1;i<=id;++i)if(!dg[i])q[V[i]].pb(i);
	for(int i=1;i<=2*n;++i){
		int x=q[i&1].back();q[i&1].pop_back();
		if(!Fa[x]&&i%2==0){if(!q[0].empty())std::swap(x,q[0].back());}
		if(Fa[x]&&!--dg[Fa[x]])q[V[Fa[x]]].pb(Fa[x]);
		printf("%d %d %d\n",a[x],b[x],c[x]);
	}
	return 0;
}