#include<cstdio>
#include<map>
const int N=200005;
int q[N],p[N];
int d[N];
std::map<int,int> mp;
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,pos=-1;
	scanf("%d",&n);
	for(int i=1;i<n;++i) scanf("%d",&q[i]),d[i]=q[i]+d[i-1];
	mp[0]=0;
	for(int i=1;i<n;++i)
	{
		if(mp.find(d[i])!=mp.end())
		{
			printf("-1\n");
			return 0;
		}
		if(mp.find(d[i]+n-1)!=mp.end())
		{
			pos=mp[d[i]+n-1]+1;
		}
		if(mp.find(d[i]-n+1)!=mp.end())
		{
			pos=i+1;
		}
		mp[d[i]]=i;
	}
	if(!~pos)
	{
		printf("-1\n");
		return 0;
	}
	p[pos]=n;
	for(int i=pos+1;i<=n;++i)
	{
		p[i]=p[i-1]+q[i-1];
	}
	for(int i=pos-1;i>=1;--i)
	{
		p[i]=p[i+1]-q[i];
	}
	for(int i=1;i<=n;++i)
	{
		if(p[i]<=0||p[i]>n)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",p[i]);
	putchar('\n');
	return 0;
}
//Dpair AK IOI