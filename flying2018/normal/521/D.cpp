#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
struct node{
	double x;
	int id;
	node(double X=0.0,int ID=0):x(X),id(ID){}
	bool operator <(const node a)const{return x>a.x;}
}c[N];
int a[N],opt[N];
vector<node>ad[N],mul;
int ans[N];
bool cmp(int x,int y){return opt[x]<opt[y];}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d",&opt[i],&x,&y);
		if(opt[i]==1) c[x]=min(c[x],node(y,i));
		if(opt[i]==2) ad[x].push_back(node(y,i));
		if(opt[i]==3) mul.push_back(node(y,i));
	}
	for(int i=1;i<=n;i++)
	if(c[i].x>a[i]) ad[i].push_back(node(c[i].x-a[i],c[i].id));
	for(int i=1;i<=n;i++)
	{
		sort(ad[i].begin(),ad[i].end());
		ll w=a[i];
		for(auto v:ad[i]) mul.push_back(node((w+v.x)/w,v.id)),w+=v.x;
	}
	sort(mul.begin(),mul.end());
	printf("%d\n",k=min(k,(int)mul.size()));
	for(int i=0;i<k;i++) ans[i]=mul[i].id;
	sort(ans,ans+k,cmp);
	for(int i=0;i<k;i++) printf("%d ",ans[i]);
	return 0;
}