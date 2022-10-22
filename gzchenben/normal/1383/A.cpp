#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,cnt[25][25];
char a[100005],b[100005];
vector<int> v[25];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		scanf("%s%s",a+1,b+1);
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]) flag=false;
			if(a[i]!=b[i]) cnt[a[i]-'a'+1][b[i]-'a'+1]++;
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=20;i++) v[i].clear();
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=20;j++) 
			{
				if(cnt[i][j]) v[j].push_back(i);
			}
		}
		int ans=0;
		for(int i=20;i>=1;i--)
		{
			if(v[i].size()<=1)
			{
//				printf("--%d %d\n",i,v[i].size());
				ans+=v[i].size();
				continue;
			}
			sort(v[i].begin(),v[i].end());
			v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
			for(int j=0;j<v[i].size()-1;j++)
			{
				v[v[i][j+1]].push_back(v[i][j]);
			}
			ans++;
		}
		printf("%d\n",ans);
	}
}