#include<algorithm>
#include<iostream>
#include<cstdio>
#include<set>
#define MN 100000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
multiset<int> st;
pair<int,pa> f[MN+5];pa last[MN+5];
int n,a[MN+5],b[MN+5],m,la[MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),f[i]=make_pair(2e9,make_pair(0,0));
	m=read();a[++n]=2e9;
	for(int i=1;i<=m;++i) b[i]=read(),st.insert(b[i]);
	sort(b+1,b+m+1,greater<int>());
	for(int i=1;i<=n;++i) if(a[i]!=-1)
	{
		la[i]=la[i-1];
		int l=1,r=i-1,mid,res=0;
		while(l<=r)
		{
			mid=l+r>>1;
			if(f[mid].first<a[i]) res=mid,l=mid+1;
			else r=mid-1;
		}
		last[i]=f[res].second;
		f[res+1]=min(f[res+1],make_pair(a[i],make_pair(i,0)));
	}
	else 
	{
		la[i]=i;int j=i-1;
		for(int k=1;k<=m;++k)
		{
			while(f[j].first>=b[k]) --j;
			f[j+1]=min(f[j+1],make_pair(b[k],make_pair(f[j].second.first,f[j].second.second+1)));	
		}
	}
	for(int x=n;x;)
	{
		int tms=last[x].second,pos=last[x].first,val=a[x];	
		for(int j=1;j<=tms;++j)
		{
			x=la[x-1];
			multiset<int>::iterator it=st.lower_bound(val);--it;
			a[x]=val=*it;st.erase(it);
		}	
		x=pos;
	}
	for(int i=1;i<n;++i) 
		if(a[i]==-1) printf("%d ",*st.begin()),st.erase(st.begin());
		else printf("%d ",a[i]);
	return 0;
}