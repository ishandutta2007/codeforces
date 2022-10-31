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
int a[N],c[N],b[N],p[N],r[N];bool vis[N];
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n,s;read(n,s);
	for(int i=1;i<=n;++i)read(a[i]),c[i]=a[i];
	std::sort(c+1,c+n+1);int m=0;
	for(int i=1;i<=n;++i)if(a[i]!=c[i])b[++m]=i,r[m]=i;else p[i]=i;
	std::sort(b+1,b+m+1,[&](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=m;++i)p[b[i]]=r[i];
	std::iota(fa+1,fa+n+1,1);for(int i=1;i<=n;++i)fa[find(i)]=find(p[i]);
	for(int i=1;i<=m;++i){
		int j=i;while(j<m&&a[b[j+1]]==a[b[i]])++j;
		for(int k=i;k<j;++k){
			int x=b[k],y=b[k+1],u=find(x),v=find(y);
			if(u!=v)fa[u]=v,std::swap(p[x],p[y]);
		}
		i=j;
	}
	int ss=0,c=0;for(int i=1;i<=n;++i)ss+=p[i]!=i;
	for(int i=1;i<=n;++i)if(p[i]!=i)c+=fa[i]==i;
	if(s>ss+c)s=ss+c;else if(s<ss)return puts("-1"),0;
	std::vector<std::vector<int>> ans;
	int rest=s<=ss+2?0:s-ss;std::vector<int> A,B;
	for(int i=1;i<=n;++i)if(p[i]!=i&&!vis[i]){
		std::vector<int> cur;for(int u=i;!vis[u];u=p[u])cur.pb(u),vis[u]=1;
		if(rest)--rest,A.insert(A.end(),cur.begin(),cur.end()),B.pb(cur[0]);
		else ans.pb(cur);
	}
	if(!A.empty())ans.pb(A),std::reverse(B.begin(),B.end()),ans.pb(B);
	printf("%d\n",SZ(ans));
	for(const auto &v:ans){
		printf("%d\n",SZ(v));
		for(auto it:v)printf("%d ",it);
		printf("\n");
	}
	return 0;
}