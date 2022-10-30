#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=800005;
struct node{
	int x,y;
	inline int dep()const{return x+y;}
	inline bool operator < (const node &o)const{return x==o.x?y<o.y:x<o.x;}
	inline bool operator == (const node &o)const{return x==o.x&&y==o.y;}
}a[N],b[N],t[N];
node lca(const node &a,const node &b){
	int X=0,Y=0,x1=a.x,y1=a.y,x2=b.x,y2=b.y;
	for(int i=30;i>=0;--i){
		int p1=(x1>>i&1)<<1|(y1>>i&1),p2=(x2>>i&1)<<1|(y2>>i&1);
		if(!p1&&!p2)continue;
		if(p1==1&&p2==1)y1-=1<<i,y2-=1<<i,Y+=1<<i;
		else if(p1==2&&p2==2)x1-=1<<i,x2-=1<<i,X+=1<<i;
		else if(p2==0){
			if(p1==1)y1=(1<<i)-1,x1=0;
			else x1=(1<<i)-1,y1=0;
		}
		else if(p1==0){
			if(p2==1)y2=(1<<i)-1,x2=0;
			else x2=(1<<i)-1,y2=0;
		}
		else break;
	}
	return {X,Y};
}
inline bool cmp(const node &a,const node &b){
	if(a==b)return false;
	node z=lca(a,b);
	if(a==z)return true;
	if(b==z)return false;
	int x1=a.x,y1=a.y,x2=b.x,y2=b.y;
	for(int i=30;i>=0;--i){
		int p1=(x1>>i&1)<<1|(y1>>i&1),p2=(x2>>i&1)<<1|(y2>>i&1);
		if(!p1&&!p2)continue;
		if(p1==1&&p2==1)y1-=1<<i,y2-=1<<i;
		else if(p1==2&&p2==2)x1-=1<<i,x2-=1<<i;
		else if(p2==0)return p1==1;
		else if(p1==0)return p2==2;
		else return p1<p2;
	}
	return false;
}
node _[N];int st[N],top,id;
std::map<node,int> __;
std::vector<int> e[N];
void ins(const node &x){
	if(!top||lca(x,_[st[top]])==_[st[top]]){st[++top]=++id,_[id]=x;return;}
	node l=lca(x,_[st[top]]);
	while(top>1&&l.dep()<=lca(x,_[st[top-1]]).dep())e[st[top-1]].pb(st[top]),--top;
	if(_[st[top]].dep()!=l.dep())e[id+1].pb(st[top]),st[top]=++id,_[id]=l;
	st[++top]=++id,_[id]=x;
}
int f[N],g[N];
std::map<int,int> mp;
void dfs(int x){
	for(auto v:e[x]){
		dfs(v),f[x]+=f[v];
		if(f[v])mp[_[v].dep()-1]^=1,mp[_[x].dep()]^=1;
	}
	if(f[x]||g[x])mp[_[x].dep()-1]^=1,mp[_[x].dep()]^=1;
}
int main(){
	int m;read(m);
	int pos=0;
	for(int i=1;i<=m;++i)read(a[i].x,a[i].y,b[i].x,b[i].y),t[++pos]=a[i],t[++pos]=b[i];
	t[++pos]={0,0},std::sort(t+1,t+pos+1,cmp),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=pos;++i)ins(t[i]);
	for(int i=1;i<top;++i)e[st[i]].pb(st[i+1]);
	for(int i=1;i<=id;++i)__[_[i]]=i;
	for(int i=1;i<=m;++i){
		int x=__[a[i]],y=__[b[i]],z=__[lca(a[i],b[i])];
		++f[x],++f[y],++g[z],f[z]-=2;
	}
	dfs(1);
	int ans=0;for(auto [x,y]:mp)if(x>=0)ans+=y;
	printf("%d\n",ans);
	return 0;
}