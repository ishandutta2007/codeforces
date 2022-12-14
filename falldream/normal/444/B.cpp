#include<iostream>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v;
int n,s,a[MN+5],b[MN+5],d,c[MN+5],pos[MN+5];
int GetNext(){return s=(37LL*s+10007)%1000000007;}
int main()
{
	n=read();d=read();s=read();
	for(int i=0;i<n;++i) a[i]=i+1;
	for(int i=0;i<n;++i) swap(a[i],a[GetNext()%(i+1)]);
	for(int i=0;i<n;++i) b[i]=i<d;
	for(int i=0;i<n;++i) swap(b[i],b[GetNext()%(i+1)]);
	for(int i=0;i<n;++i) if(pos[a[i]]=i,b[i]) v.push_back(i);
	int Mx=min(10000000/d,n);
	for(int i=n-Mx+1;i<=n;++i)for(int j=0;j<v.size();++j) if(v[j]+pos[i]<n) 
		c[v[j]+pos[i]]=max(c[v[j]+pos[i]],i); 
	if(Mx!=n)
	{
		for(int i=0;i<n;++i) if(c[i]<=n-Mx)
			for(int j=0;j<v.size()&&v[j]<=i;++j)
				c[i]=max(c[i],a[i-v[j]]);
	}
	for(int i=0;i<n;++i) printf("%d\n",c[i]);
	return 0;
}