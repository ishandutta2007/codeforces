#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=1005;
int tt,n,r[xx],c[xx];
//int ans[xx][xx],res[xx][xx],C;
//void print(int op)
//{
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<(op==0?ans[i][j]:res[i][j])<<" \n"[j==n];
//}
//int vs[xx];
int ans[xx][xx];
//23
struct nod{int a,b,c,d;};
vector<nod>v;
void cont(int);
void solve(int);
void cont(int n)
{
	for(int i=1;i<n;i++)r[i]=r[i+1]-1;
	for(int i=1;i<n;i++)c[i]=c[i+1]-1;
	solve(n-1);
	for(auto &it:v)it.a++,it.b++,it.c++,it.d++;
	return;
}
void solve(int n)//n*nr1~rn 
{
	if(n==1)return;
	if(r[1]==1&&c[1]==1)return cont(n);
	int id=0;
	for(int i=1;i<=n;i++)if(r[i]==1)id=i;
	int _id=0;
	for(int i=1;i<=n;i++)if(c[i]==1)_id=i;
	if(id==n)
	{
		c[_id]=c[1],r[n]=r[1];
		cont(n);
		v.push_back({n,1,1,_id});
		return ;
	}
	if(_id==n)
	{
		r[id]=r[1],c[n]=c[1];
		cont(n);
		v.push_back({1,n,id,1});
		return;
	}
	c[_id]=c[n],c[n]=c[1];
	r[id]=r[n],r[n]=r[1];
	cont(n);
	v.push_back({n,1,1,_id});
	v.push_back({1,n,id,1});
	return;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)r[i]=read();//iri 
	for(int i=1;i<=n;i++)c[i]=read();
	solve(n);
	cout<<v.size()<<"\n";
	for(auto it:v)cout<<it.a<<' '<<it.b<<" "<<it.c<<" "<<it.d<<"\n";
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	C=n+1;
//	for(int i=1;i<=n;i++)
//	{
//		if(vs[i])continue;
//		int x=i;
//		vs[i]=1;
//		while(r[x]!=i)
//		{
//			++tt,--C;
//			res[x][C]=tt,res[r[x]][C]=tt;// 
//			x=r[x],vs[x]=1;
//		}
//		// 
//	}
//	print(1);
//	int R=n+1;
//	for(int i=1;i<=n;i++)vs[i]=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(vs[i])continue;
//		int x=i;
//		vs[i]=1;
//		// 
//		while(c[x]!=i)
//		{
//			R--;// 
//			int L=0,R=0;
//			for(int j=1;j<=n;j++)if(res[R][j]){}
//			x=c[x],vs[x]=1;
//		}
//	}
	pc('1',1);
	return 0;
}