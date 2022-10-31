#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;typedef std::pair<int,int> pi;
std::bitset<N> f[N],g[N];int siz[N];
struct comp{inline bool operator ()(int a,int b)const{return siz[a]==siz[b]?a<b:siz[a]<siz[b];}};
std::set<int,comp> S;std::set<pi> all;
bool check(int x,int y){return (f[x]&f[y])!=f[x];}
int main(){
	int n,m,q;read(n,m,q);
	for(int i=1;i<=m;++i)g[i]=g[i-1],g[i].set(i);
	for(int i=1;i<=n;++i)S.insert(i);
	int a,l,r;
	while(q--){
		read(a,l,r);auto it=S.find(a);int pre=-1,suf=-1;
		if(it!=S.begin())pre=*--it,++it;
		if(++it!=S.end())suf=*it;
		if(pre!=-1&&check(pre,a))all.erase({pre,a});
		if(suf!=-1&&check(a,suf))all.erase({a,suf});
		if(pre!=-1&&suf!=-1&&check(pre,suf))all.insert({pre,suf});
		S.erase(--it),f[a]^=g[r]^g[l-1],siz[a]=f[a].count();
		it=S.insert(a).first,pre=-1,suf=-1;
		if(it!=S.begin())pre=*--it,++it;
		if(++it!=S.end())suf=*it;
		if(pre!=-1&&check(pre,a))all.insert({pre,a});
		if(suf!=-1&&check(a,suf))all.insert({a,suf});
		if(pre!=-1&&suf!=-1&&check(pre,suf))all.erase({pre,suf});
		if(all.empty())puts("-1");
		else{
			int x1=all.begin()->first,x2=all.begin()->second;
			int y1=(f[x1]^(f[x1]&f[x2]))._Find_first(),y2=(f[x2]^(f[x1]&f[x2]))._Find_first();
			if(x1>x2)std::swap(x1,x2);
			if(y1>y2)std::swap(y1,y2);
			printf("%d %d %d %d\n",x1,y1,x2,y2);
		}
	}
	return 0;
}