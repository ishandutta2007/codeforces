#include<cstdio> 
#include<map>
#include<algorithm>
using namespace std;
int n,t,a[200005];
map<int,bool> mp;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			int tmp=((a[i]+i)%n+n)%n;
			if(mp[tmp])
			{
				printf("NO\n");
				flag=false;
				break;
			}
			mp[tmp]=true;
		}
		if(flag) printf("YES\n");
	}
}