#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#define inf 8e18
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define ll long long
#define vt vector<node>
using namespace std; 
inline ll read()
{
    ll t=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')       {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();                
    return t*f;
}
struct node{int x,y,z,id;};
inline ll det(const node &a, const node &b, const node &c) 
{
  ll p=(ll)b.y*c.z-(ll)b.z*c.y;
  ll q=(ll)b.x*c.z-(ll)b.z*c.x;
  ll r=(ll)b.x*c.y-(ll)b.y*c.x;
  return a.x*p-a.y*q+a.z*r;
}
struct A{int f,s;};
vector<A> ans;
inline void dfs(vt &q,int k)
{
	int n=q.size();
	if(n<=k)
	{
		puts("YES");
		printf("%d\n",n+ans.size());
		For(i,0,n-1)	printf("%d -1\n",q[i].id);
		if(ans.size()!=0)
			For(i,0,ans.size()-1)	printf("%d %d\n",ans[i].f,ans[i].s);
		exit(0);	
	}
	if(!k)	return;
	vt tmp;
	For(T,0,30*k)
	{
		int x=rand()%n,y=rand()%n;
		while(y==x)	y=rand()%n;
		const node &T1=q[x],&T2=q[y];
		if(T1.x*T2.y==T1.y*T2.x)	continue;
		tmp.clear();
		For(i,0,n-1)
			if(i!=x&&i!=y&&det(T1,T2,q[i]))	
				tmp.push_back(q[i]);
	 	A mmp;
	 	mmp.f=q[x].id;mmp.s=q[y].id;
	 	int TTT=tmp.size();
	 	if (TTT>max(k-1,n-n/k))
			continue;
		ans.push_back(mmp);
		dfs(tmp,k-1);
		ans.pop_back();
		if(n-tmp.size()>k)	return;
	}
}
int n,m;
int main()
{
	n=read();m=read();
	vt q;
	For(i,1,n)
	{
		node tmp;
		tmp.x=read();tmp.y=read();tmp.z=read();tmp.id=i;
		q.push_back(tmp);
	}
	dfs(q,m);
	puts("NO");
}