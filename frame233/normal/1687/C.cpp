#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;typedef std::pair<ll,int> pr;
int a[N],l[N],r[N];ll sa[N];std::vector<int> vec[N],Q;bool mark[N];
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void upd(int l,int r){
	if(sa[r]!=0)return;
	for(int i=find(l);i<=r;i=find(i)){
		sa[i]=0,fa[i]=find(i+1);
		for(auto it:vec[i])if(sa[::r[it]]==0&&sa[::l[it]-1]==0&&!mark[it])mark[it]=1,Q.pb(it);
	}
}
void MAIN(){
	int n,m;read(n,m);memset(mark,0,m+3);
	for(int i=0;i<=n;++i)vec[i].clear();
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x;i<=n;++i)read(x),a[i]-=x;
	for(int i=1;i<=n;++i)sa[i]=sa[i-1]+a[i];
	std::iota(fa+1,fa+n+2,1);
	for(int i=1,l,r;i<=m;++i){read(l,r),::l[i]=l,::r[i]=r;if(sa[r]==0&&sa[l-1]==0)mark[i]=1,Q.pb(i);else vec[l-1].pb(i),vec[r].pb(i);}
	while(!Q.empty()){int id=Q.back();Q.pop_back(),upd(l[id],r[id]);}
	for(int i=1;i<=n;++i)if(sa[i])return puts("NO"),void();
	puts("YES");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}