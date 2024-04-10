#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt[1005],mtx[25][25];
vector<int> all;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*n;i++) 
	{
		int x;
		scanf("%d",&x);
		if(!cnt[x]) all.push_back(x);
		cnt[x]++;
	}
	if(n%2==0)
	{
		for(int i=0;i<all.size();i++)
		{
			if(cnt[all[i]]%4)
			{
				printf("NO\n");
				return 0;
			}
		}
		printf("YES\n");
		int row=1,col=1;
		for(int i=0;i<all.size();i++)
		{
			int x=all[i];
			while(cnt[x]) 
			{
				mtx[row][col]=x;
				if(col==n/2) col=1,row++;
				else col++;
				cnt[x]-=4;
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n/2;j++)
			{
				int x=mtx[i][j];
				mtx[n-i+1][j]=mtx[i][n-j+1]=mtx[n-i+1][n-j+1]=x;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",mtx[i][j]);
			}
			puts("");
		}
	}
	else
	{
		int bad=0,bad2=0;
		for(int i=0;i<all.size();i++) 
		{
			if(cnt[all[i]]&1) bad++;
			if(cnt[all[i]]%4==2||cnt[all[i]]%4==3) bad2++;
		}
		if(bad>1||bad2>n)
		{
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i=0;i<all.size();i++)
		{
			if(cnt[all[i]]&1) mtx[n/2+1][n/2+1]=all[i],cnt[all[i]]--;
		}
		int row=1,col=1,ok=0;
		for(int i=0;i<all.size();i++)
		{
			int x=all[i];
			if(ok) break;
			while(cnt[x]>=4) 
			{
				mtx[row][col]=x;
				cnt[x]-=4;
				if(col==n/2) col=1,row++;
				else col++;
				if(row>n/2)
				{
					ok=1;
					break;
				}
			}
		}
		row=1,ok=0;
		for(int i=0;i<all.size();i++)
		{
			int x=all[i];
			if(ok) break;
			while(cnt[x])
			{
				mtx[n/2+1][row]=x;
				row++;
				cnt[x]-=2;
				if(row==n/2+1)
				{
					ok=1;
					break;
				}
			}
		}
		ok=0,row=1;
		for(int i=0;i<all.size();i++)
		{
			int x=all[i];
			if(ok) break;
			while(cnt[x])
			{
				mtx[row][n/2+1]=x;
				row++;
				cnt[x]-=2;
				if(row==n/2+1)
				{
					ok=1;
					break;
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n/2;j++)
			{
				int x=mtx[i][j];
				mtx[n-i+1][j]=mtx[i][n-j+1]=mtx[n-i+1][n-j+1]=x;
			}
		}
		for(int i=1;i<=n/2;i++) mtx[n/2+1][n-i+1]=mtx[n/2+1][i],mtx[n-i+1][n/2+1]=mtx[i][n/2+1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",mtx[i][j]);
			}
			puts("");
		}
	}
	return 0;
}/*
3
2 2 2
2 3 3
3 22 21 21*/