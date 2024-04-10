#include<bits/stdc++.h>
#define ll long long
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
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
// 
//
const int xx=2e6+5;
int rnx[xx],cnx[xx],v[xx],n,m,q;
int id(int a,int b){return a*(m+1)+b+1;}
int get(int x,int y)
{
	int ids=id(0,0);
	while(x--)ids=cnx[ids];
	while(y--)ids=rnx[ids];
	return ids;
}
vector<int> runc(int x,int y,int sz)
{
	vector<int>v;
	int id=get(x,y);
	while(sz--)v.push_back(id=cnx[id]);
	return v;
}
vector<int> runr(int x,int y,int sz)
{
	vector<int>v;
	int id=get(x,y);
	while(sz--)v.push_back(id=rnx[id]);
	return v;
}
void cgc(vector<int>a,vector<int>b,int sz)//r 
{
	for(int i=0;i<sz;i++)
		swap(rnx[a[i]],rnx[b[i]]);
}
void cgr(vector<int>a,vector<int>b,int sz)//c 
{
	for(int i=0;i<sz;i++)
		swap(cnx[a[i]],cnx[b[i]]);
}
void print()
{
	int nid=id(0,0);
	for(int i=1;i<=n;i++)
	{
		nid=cnx[nid];
		int use=nid;
		for(int j=1;j<=m;j++)
			cout<<v[use=rnx[use]]<<" \n"[j==m];
	}
}
signed main(){
	n=read(),m=read(),q=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<m;j++)
			rnx[id(i,j)]=id(i,j+1);
	for(int i=0;i<n;i++)
		for(int j=0;j<=m;j++)
			cnx[id(i,j)]=id(i+1,j);
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=m;j++)cout<<i<<" "<<j<<" "<<id(i,j)<<"\n";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			v[id(i,j)]=read();
//	print();
	while(q--)
	{
		int x[2],y[2],h,w;
		for(int I=0;I<=1;I++)x[I]=read(),y[I]=read();
		h=read(),w=read();
		// 
		vector<int>CF[2],CB[2],RF[2],RB[2];// 
		for(int I=0;I<=1;I++)
		{
			CF[I]=runc(x[I]-1,y[I]-1,h);
			CB[I]=runc(x[I]-1,y[I]-1+w,h);
			RF[I]=runr(x[I]-1,y[I]-1,w);
			RB[I]=runr(x[I]-1+h,y[I]-1,w);
		}
		cgc(CF[0],CF[1],h);
		cgc(CB[0],CB[1],h);
		cgr(RF[0],RF[1],w);
		cgr(RB[0],RB[1],w);
	}
	print();
	pc('1',1);
	return 0;
}