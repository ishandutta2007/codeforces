#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=150005;
const int MAXN=1000005;
typedef std::pair<int,int> pi;
int md[MAXN],p[MAXN],pos;bool pr[MAXN];
void sieve(){
	for(int i=2;i<MAXN;++i){
		if(!pr[i])p[++pos]=i,md[i]=pos;
		for(int j=1;i*p[j]<MAXN;++j){
			pr[i*p[j]]=true,md[i*p[j]]=j;
			if(i%p[j]==0)break;
		}
	}
}
std::vector<int> _(int x){
	std::vector<int> ans;
	while(x>1){
		if(ans.empty()||ans.back()!=md[x])ans.pb(md[x]);
		x/=p[md[x]];
	}
	return ans;
}
int fa[MAXN],A[N],c[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<pi> all;
int main(){
	sieve();
	int n,q;read(n,q);
	std::iota(fa+1,fa+pos+1,1);
	for(int i=1;i<=n;++i){
		read(A[i]);
		std::vector<int> a=_(A[i]);
		int qwq=c[i]=a.back();
		for(auto it:a)fa[find(it)]=find(qwq);
	}
	for(int i=1;i<=n;++i){
		std::vector<int> a=_(A[i]),b=_(A[i]+1);
		for(auto it:b)a.pb(it);
		for(int i=0;i<SZ(a);++i)for(int j=i+1;j<SZ(a);++j)if(find(a[i])!=find(a[j])){
			int x=find(a[i]),y=find(a[j]);if(x>y)std::swap(x,y);
			all.pb({x,y});
		}
	}
	std::sort(all.begin(),all.end());
	int a,b;
	while(q--){
		read(a,b);
		int x=find(c[a]),y=find(c[b]);if(x>y)std::swap(x,y);
		if(x==y)puts("0");
		else if(std::binary_search(all.begin(),all.end(),pi{x,y}))puts("1");
		else puts("2");
	}
	return 0;
}