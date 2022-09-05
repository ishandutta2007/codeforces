//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m;
vector<int>con[50011];
int col[50011];
bool ans[1000111];
int main()
{
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<y)swap(x,y);
		con[x].PB(y);
	}
	for(int i=1;i<=n;i++)
	{
		int cnt0=0,cnt1=0;
		for(int j=0;j<con[i].size();j++)
		{
			if(col[con[i][j]]==0)cnt0++;else cnt1++;
		}
		if(cnt0>=cnt1)col[i]=1;else col[i]=0;
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		con[i].clear();
		int tn;
		scanf("%d",&tn);
		for(int j=1;j<=tn;j++)
		{
			int x;
			scanf("%d",&x);
			con[i].PB(x);
			mx=max(mx,x);
		}
	}
	while(true)
	{
		for(int i=1;i<=mx;i++)ans[i]=rand()%2;
		bool ok=1;
		for(int i=1;i<=n;i++)
		{
			bool t=0;
			for(int j=0;j<con[i].size();j++)
			{
				if(ans[con[i][j]]==col[i])
				{
					t=1;
					break;
				}
			}
			if(!t)
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<con[i].size();j++)
				{
					if(ans[con[i][j]]==col[i])
					{
						printf("%d ",con[i][j]);
						break;
					}
				}
			}
			puts("");
			for(int i=1;i<=mx;i++)putchar('1'+ans[i]),putchar(' ');
			return 0;
		}
	}
	return 0;
}