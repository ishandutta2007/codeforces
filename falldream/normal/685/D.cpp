#include<algorithm> 
#include<iostream>
#include<cstdio>
#include<set>
#define MN 100000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
multiset<int> s;
int n,K,top,q[MN+5];
pair<int,int> a[MN+5];
long long ans[MN+5];
int main()
{
	n=read();K=read();
	for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1);
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i+1;j<=n&&a[j].first-a[j-1].first<K;++j);--j;
		s.clear();
		for(int k=a[i].first,l=i,r=i;k<=a[j].first+K-1;++k)
		{
			for(;l<=j&&a[l].first<=k;++l) s.insert(a[l].second);
			for(;r<=j&&a[r].first+K<=k;++r) s.erase(s.lower_bound(a[r].second));
			top=0;
			for(multiset<int>::iterator it=s.begin();it!=s.end();++it) q[++top]=*it;
			for(int L=1,R=1,pre=q[1]-1;L<=top;)
			{
				if(R<=top&&q[R]<=q[L]+K) ans[R-L]+=q[R]-pre,pre=q[R],++R;
				else ans[R-L]+=q[L]+K-pre,pre=q[L]+K,++L;
			}
		}
	}
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]); 
	return 0;
}