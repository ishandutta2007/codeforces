#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],n,m;
set<int>s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		s.clear();
		long long las=0,ans=0;
		for(int i=1;i<=m;i++)
		{
			ans++;
			if(s.count(b[i]))
			{
				s.erase(b[i]);
				continue;
			}
			while(1)
			{
				las++;
				s.insert(a[las]);
				if(a[las]==b[i])
					break;
			}
			s.erase(b[i]);
			ans+=s.size()*2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}