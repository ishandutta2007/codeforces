#include<iostream>
#include<cstdio>
#include<vector>
#define MN 400000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[MN+5],s[MN+5],S[MN+5],f[MN+5],Ans[MN+5],mx=0;
vector<int>v[MN+5];
vector<pair<int,int> >q[MN+5];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read(),s[i]=2e9;
	S[0]=int(2e9);
	for(int i=n;i;--i)
	{
		int l=0,r=n,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			if(S[mid]>a[i]) res=mid,l=mid+1;
			else r=mid-1;	
		}
		mx=max(mx,f[i]=res+1);
		if(a[i]>S[res+1]) S[res+1]=a[i],v[res+1].push_back(i);
	}
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read();
		q[x].push_back(make_pair(y,i));	
	}
	for(int i=1,R=v[mx][0]-1;i<=n;++i)
	{
		if(v[f[i]].size()&&v[f[i]].back()==i) v[f[i]].pop_back(),S[f[i]]=(v[f[i]].size()?a[v[f[i]].back()]:0);
		int l=0,r=n,mid,res,res1,res2;
		for(int j=0;j<q[i].size();++j)
		{
			res1=res2=0;
			l=0,r=n;
			while(l<=r)
			{
				mid=l+r>>1;
				if(S[mid]>q[i][j].first) res1=mid,l=mid+1;
				else r=mid-1;	
			}
			l=0,r=n;
			while(l<=r)
			{
				mid=l+r>>1;
				if(s[mid]<q[i][j].first) res2=mid,l=mid+1;
				else r=mid-1;
			}
			//cout<<q[i][j].second<<" "<<q[i][j].first<<" "<<res1<<" "<<res2<<" "<<R<<" "<<S[1]<<endl;
			Ans[q[i][j].second]=max(res1+res2+1,mx-(R<i));
		}
		l=0,r=n;
		while(l<=r)
		{
			mid=l+r>>1;
			if(s[mid]<a[i]) res=mid,l=mid+1;
			else r=mid-1;
		}
		s[res+1]=min(s[res+1],a[i]);
		int exlen=mx-res-1;
		if(!exlen) R=n;
		else 
		{
			l=0,r=v[exlen].size()-1;int res3=0;
			while(l<=r)
			{
				mid=l+r>>1;
				if(a[v[exlen][mid]]>a[i]) res3=v[exlen][mid]-1,r=mid-1;
				else l=mid+1;	
			}
			R=max(R,res3);
		}
	}
	for(int i=1;i<=m;++i) printf("%d\n",Ans[i]);
	return 0;
}