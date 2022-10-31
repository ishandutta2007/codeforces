#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,inf=0x7fffffff;
int x[N],d[N],n,f[N],g[N],st[N];
struct node{int p,x,op;inline bool operator < (const node &o)const{return p<o.p;}}q[N*4];
std::set<int> s0,s1;
int main(){
	read(n);
	for(int i=0;i<=n+1;++i)read(x[i]);
	for(int i=1;i<=n;++i)read(d[i]);
	f[0]=x[n+1];
	for(int i=1,top=0;i<=n;++i){
		while(top&&f[st[top]]<x[i])--top;
		f[i]=std::min((long long)x[n+1],2LL*d[i]+x[st[top]]);
		while(top&&f[st[top]]<=f[i])--top;
		st[++top]=i;
	}
	g[n+1]=0,st[0]=n+1;
	for(int i=n,top=0;i>=1;--i){
		while(top&&g[st[top]]>x[i])--top;
		g[i]=x[st[top]]-2*d[i];
		while(top&&g[st[top]]>=g[i])--top;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i)if(f[i]>=x[n+1])return puts("0"),0;
	int pos=0;for(int i=0;i<=n+1;++i)if(x[i]<f[i])q[++pos]={x[i],x[i],0},q[++pos]={f[i]+1,x[i],2};
	for(int i=0;i<=n+1;++i)if(g[i]<x[i])q[++pos]={g[i],x[i],1},q[++pos]={x[i],x[i],3};
	std::sort(q+1,q+pos+1);int ans=inf;
	for(int i=1;i<=pos;++i){
		int j=i;while(j<pos&&q[j+1].p==q[i].p)++j;
		for(int k=i;k<=j;++k){
			if(q[k].op==0)s0.insert(q[k].x);
			else if(q[k].op==1)s1.insert(q[k].x);
			else if(q[k].op==2)s0.erase(q[k].x);
			else s1.erase(q[k].x);
		}
		if(!s0.empty()&&!s1.empty())ans=std::min(ans,*s1.begin()-*s0.rbegin());
		i=j;
	}
	if(ans%2==0)printf("%d\n",ans/2);else printf("%d.5\n",ans/2);
	return 0;
}