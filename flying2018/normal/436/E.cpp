#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 300010
#define PQ priority_queue<node>
using namespace std;
struct node{
	int x,u;
	node(int X=0,int U=0):x(X),u(U){}
	bool operator <(const node a)const{return x>a.x;}
};
PQ q1,q2,q3,q4,q5;
int d[N];
void upd(PQ &a,int t){while(!a.empty() && d[a.top().u]!=t) a.pop();}
int a[N],b[N];
void t0(int u){d[u]=0;q1.push(node(a[u],u)),q4.push(node(b[u],u));}
void t1(int u){d[u]=1;q2.push(node(b[u]-a[u],u));q3.push(node(-a[u],u));}
void t2(int u){d[u]=2;q5.push(node(a[u]-b[u],u));}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) q1.push(node(a[i],i)),q4.push(node(b[i],i));
	long long ans=0;
	while(m --> 0)
	{
		upd(q1,0),upd(q2,1),upd(q3,1),upd(q4,0),upd(q5,2);
		int mx=2e9,id=0,x=0;
		if(!q1.empty()){x=q1.top().x;if(x<mx) mx=x,id=1;}
		if(!q2.empty()){x=q2.top().x;if(x<mx) mx=x,id=2;}
		if(!q3.empty() && !q4.empty()){x=q3.top().x+q4.top().x;if(x<mx) mx=x,id=3;}
		if(!q4.empty() && !q5.empty()){x=q4.top().x+q5.top().x;if(x<mx) mx=x,id=4;}
		ans+=mx;
		if(id==1) t1(q1.top().u);
		else if(id==2) t2(q2.top().u);
		else if(id==3) t0(q3.top().u),t2(q4.top().u);
		else t1(q5.top().u),t2(q4.top().u);
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) putchar('0'+d[i]);
	return 0;
}