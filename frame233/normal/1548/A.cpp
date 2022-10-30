#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
std::set<int> e[N];
int ans;
inline int get(int u){return e[u].empty()||u>*e[u].rbegin();}
void add(int u,int v){
	ans-=get(u),ans-=get(v);
	e[u].insert(v),e[v].insert(u);
	ans+=get(u),ans+=get(v);
}
void del(int u,int v){
	ans-=get(u),ans-=get(v);
	e[u].erase(v),e[v].erase(u);
	ans+=get(u),ans+=get(v);
}
int main(){
	int n,m;read(n,m);ans=n;
	int opt,x,y;for(int i=1;i<=m;++i)read(x,y),add(x,y);
	int q;read(q);
	while(q--){
		read(opt);
		if(opt==3)printf("%d\n",ans);
		else{
			read(x,y);
			(opt==1?add:del)(x,y);
		}
	}
	return 0;
}