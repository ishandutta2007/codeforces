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
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int dir[8][2]={{1,3},{0,2},{1,4},{0,5},{2,7},{3,6},{5,7},{4,6}};
int n;
int d[33];
bool a[333][333][8],b[333][333][8],ans[333][333];
void solve(int l)
{
	memset(b,0,sizeof(b));
	for(int i=0;i<333;i++)
	{
		for(int j=0;j<333;j++)
		{
			for(int k=0;k<8;k++)
			{
				if(!a[i][j][k])continue;
				for(int t=1;t<=l;t++)
				{
					ans[i+dx[k]*t][j+dy[k]*t]=1;
				}
				for(int t=0;t<2;t++)b[i+dx[k]*l][j+dy[k]*l][dir[k][t]]=1;
			}
		}
	}
	swap(a,b);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	d[1]--;
	a[155][155][4]=1;
	ans[155][155]=1;
	for(int i=1;i<=n;i++)
	{
		solve(d[i]);
	}
	int cnt=0;
	for(int i=0;i<333;i++)
	{
		for(int j=0;j<333;j++)
		{
			cnt+=ans[i][j];
		}
	}
	cout<<cnt<<endl;
	return 0;
}