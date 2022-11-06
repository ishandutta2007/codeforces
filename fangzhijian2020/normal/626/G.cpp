#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,t,Q,tp,x,tot[200005],opt[200005];double p[200005],l[200005],sum;
struct node{
	double x;int rk,id,opt;
	bool operator<(const node&a)const{
		return x<a.x;
	}
	bool operator>(const node&a)const{
		return x>a.x;
	}
};
priority_queue<node>q;
priority_queue<node,vector<node>,greater<node> >qs;
node Topq(){
	while(!q.empty()){
		node now=q.top();
		if(now.opt==opt[now.id]&&now.rk==tot[now.id]+1&&now.rk<=l[now.id])break;
		q.pop();
	}
	return q.top();
}
node Topqs(){
	while(!qs.empty()){
		node now=qs.top();
		if(now.opt==opt[now.id]&&now.rk==tot[now.id])break;
		qs.pop();
	}
	return qs.top();
}
void add(node now){
	q.pop();++tot[now.id];
	double tmp=tot[now.id]+1;
	if(tot[now.id]<l[now.id]){
		q.push((node){p[now.id]*(l[now.id]/(tmp+l[now.id])/(tmp+l[now.id]-1)),tot[now.id]+1,now.id,opt[now.id]});
	}
	tmp=tot[now.id];
	if(tot[now.id]){
		qs.push((node){p[now.id]*(l[now.id]/(tmp+l[now.id])/(tmp+l[now.id]-1)),tot[now.id],now.id,opt[now.id]});
	}	
}
void del(node now){
	qs.pop();--tot[now.id];
	double tmp=tot[now.id]+1;
	if(tot[now.id]<l[now.id]){
		q.push((node){p[now.id]*(l[now.id]/(tmp+l[now.id])/(tmp+l[now.id]-1)),tot[now.id]+1,now.id,opt[now.id]});
	}
	tmp=tot[now.id];
	if(tot[now.id]){
		qs.push((node){p[now.id]*(l[now.id]/(tmp+l[now.id])/(tmp+l[now.id]-1)),tot[now.id],now.id,opt[now.id]});
	}	
}
void Add(int id){
	double tmp=tot[id]+1;
	if(tot[id]<l[id]){
		q.push((node){p[id]*(l[id]/(tmp+l[id])/(tmp+l[id]-1)),tot[id]+1,id,opt[id]}); 
	}
	tmp=tot[id];
	if(tot[id]){
		qs.push((node){p[id]*(l[id]/(tmp+l[id])/(tmp+l[id]-1)),tot[id],id,opt[id]}); 
	}
}
int main(){
	n=read();t=read();Q=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i)l[i]=read();
	++n;p[n]=0;l[n]=t+1;
	for(int i=1;i<=n;++i)q.push((node){p[i]/(1+l[i]),1,i,0});
	for(int i=1;i<=t;++i){
		node now=q.top();q.pop();
		sum+=now.x;++tot[now.id];qs.push(now);
		double tmp=tot[now.id]+1;
		if(tot[now.id]<l[now.id]){
			q.push((node){p[now.id]*(l[now.id]/(tmp+l[now.id])/(tmp+l[now.id]-1)),now.rk+1,now.id,0});
		}
	}
	for(int i=1;i<=Q;++i){
		tp=read();x=read();
		if(tp==2){
			sum-=p[x]*tot[x]/(tot[x]+l[x]);--l[x];++opt[x];
			if(l[x]<tot[x]){
				--tot[x];Add(x);
				node now=Topq();
				sum+=now.x;add(now);
			}
			else Add(x);
			if(tot[x])sum+=p[x]*tot[x]/(tot[x]+l[x]);
		}
		else{
			sum-=p[x]*tot[x]/(tot[x]+l[x]);++l[x];++opt[x];
			sum+=p[x]*tot[x]/(tot[x]+l[x]);
			Add(x);
		}
		while(Topqs().x<Topq().x){
			node now1=Topqs(),now2=Topq();
			sum+=now2.x-now1.x;
			del(now1);add(now2);
		}
		printf("%.10lf\n",sum);
	}
	return 0;
}