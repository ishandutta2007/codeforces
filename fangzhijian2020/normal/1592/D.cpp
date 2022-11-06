#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
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
int T,n,k,h[200005],cnt=1,x[200005],y[200005],top,s[200006],tot,p[200005],B,vis[200006],now,tp[20005];
struct edge{
	int to,next;
}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void dfs(int x,int prt){
	int i,y;if(top>=B)return;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		if(!vis[i>>1])s[++top]=(i>>1);
		if(top>=B)return;
		dfs(y,x);if(top>=B)return;
	}
}
int main(){
	n=read();now=n-1;
	for(int i=1;i<n;++i){
		x[i]=read();y[i]=read();
		add(x[i],y[i]);add(y[i],x[i]);
	}
	cout<<"? "<<n<<" ";
	for(int i=1;i<=n;++i){
		cout<<i<<" ";
	}
	cout<<endl;int Max=read();
	while(now>1){
		B=(now+1)/2;top=0;dfs(1,0);
		for(int i=1;i<=top;++i){
			tp[x[s[i]]]=tp[y[s[i]]]=1;
		}
		tot=0;
		for(int i=1;i<=n;++i){
			if(tp[i]){
				p[++tot]=i;tp[i]=0;
			}
		}
		cout<<"? "<<tot<<" ";
		for(int i=1;i<=tot;++i)cout<<p[i]<<" ";
		cout<<endl;
		int tmp=read();
		if(tmp==Max){
			for(int i=1;i<n;++i)vis[i]=1;
			for(int i=1;i<=top;++i)vis[s[i]]=0;
			now=top;
		}
		else{
			for(int i=1;i<=top;++i)vis[s[i]]=1;
			now-=top;
		}
	}
	for(int i=1;i<n;++i){
		if(!vis[i]){
			cout<<"! "<<x[i]<<" "<<y[i]<<endl;
			return 0;
		}
	}
	return 0;
}