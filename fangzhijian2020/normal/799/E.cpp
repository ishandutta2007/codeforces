#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Mxdt=100000,INF=2e9+1;
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
struct node{
	int v,id;
	bool operator<(const node&a)const{
		return v>a.v;
	}
};
priority_queue<node>q[4],Q;long long ans;
int n,m,k,t,x,cnt1,cnt2,c[200005],opt[200005],vis[200005];
bool empty(int opt){
	while(!q[opt].empty()){
		if(vis[q[opt].top().id])q[opt].pop();else break;
	}
	return q[opt].empty();
}
bool empty(){
	while(!Q.empty()){
		if(!vis[Q.top().id])Q.pop();else break;
	}
	return Q.empty();
}
int main(){
	n=read();m=read();k=m-read();if(k<0){puts("-1");return 0;}
	for(int i=1;i<=n;++i)c[i]=read();
	t=read();for(int i=1;i<=t;++i){x=read();opt[x]|=1;}
	t=read();for(int i=1;i<=t;++i){x=read();opt[x]|=2;}
	for(int i=1;i<=n;++i)q[opt[i]].push((node){c[i],i});
	for(int i=1;i<=m;++i){
		int Min=INF,id=-1,id1=-1,id2=-1,opt=-1;
		if(cnt1<k&&cnt2<k&&!empty(0)&&q[0].top().v<Min){
			opt=0;Min=q[0].top().v;id=q[0].top().id;
		}
		if(cnt2<k&&!empty(1)&&q[1].top().v<Min){
			opt=1;Min=q[1].top().v;id=q[1].top().id;
		}
		if(cnt1<k&&!empty(2)&&q[2].top().v<Min){
			opt=2;Min=q[2].top().v;id=q[2].top().id;
		}
		if(!empty(3)&&q[3].top().v<Min){
			opt=3;Min=q[3].top().v;id=q[3].top().id;
		}
		if(!empty(1)&&!empty(2)&&!empty()&&q[1].top().v+q[2].top().v+Q.top().v<Min){
			opt=-1;Min=q[1].top().v+q[2].top().v+Q.top().v;
			id=Q.top().id;id1=q[1].top().id;id2=q[2].top().id;
		}
		if(Min==INF){puts("-1");return 0;}ans+=Min;
		if(opt>=0){
			if(!(opt&1))++cnt1;if(!(opt&2))++cnt2;
			vis[id]=1;q[opt].pop();
			if(opt==0)Q.push((node){-c[id],id});
		}
		else{
			q[1].pop();q[2].pop();Q.pop();
			vis[id1]=1;vis[id2]=1;vis[id]=0;
			q[0].push((node){c[id],id});
		}
	}
	cout<<ans<<'\n';
	return 0;
}