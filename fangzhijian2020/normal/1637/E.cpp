#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int Mxdt=100000;const long long INF=1e15;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,m,a[300005],tot,vis[300005];long long ans;
struct node{
	int x,v;
	bool operator<(const node&a)const{
		return v<a.v;
	}
}q[300005];
map<int,int>mp;
struct Pair{int x,y;
	bool operator<(const Pair&a)const{
		return y<a.y;
	}
}t[300005];
struct S{
	int x;
	bool operator<(const S&a)const{
		if(q[x].x==q[a.x].x)return x<a.x;
		return q[x].x>q[a.x].x;
	}
};
set<S>s[300005];
set<S>::iterator it;
void cal(int id,int x,int c){
	for(it=s[id].begin();it!=s[id].end();++it){
		if(!vis[(*it).x]){
			ans=max(ans,1ll*(x+q[(*it).x].x)*(c+id));return;
		}
	}
}
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();ans=0;tot=0;
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n;i=j){
			while(j<=n&&a[j]==a[i])++j;
			q[++tot]=(node){a[i],j-i};
		}
		sort(q+1,q+tot+1);mp.clear();
		for(int i=1;i<=tot;++i)mp[q[i].x]=i;
		for(int i=1;i<=m;++i){
			t[i].x=mp[read()];t[i].y=mp[read()];
			if(t[i].x>t[i].y)swap(t[i].x,t[i].y);
		}
		sort(t+1,t+m+1);int mx=0;
		for(int i=1,now=1,Next=1;i<=tot;++i,now=Next){
			while(Next<=m&&t[Next].y==i)++Next;
			for(int j=now;j<Next;++j)vis[t[j].x]=1;
			for(int j=1;j<=mx;++j){
				if(s[j].size())cal(j,q[i].x,q[i].v);
			}
			mx=max(mx,q[i].v);s[q[i].v].insert((S){i});
			for(int j=now;j<Next;++j)vis[t[j].x]=0;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=mx;++i)s[i].clear();
	}
	return 0;
}