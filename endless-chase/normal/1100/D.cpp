#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int X,Y,x[777],y[777],a,b,c,cnt1,cnt2,cnt3,cnt4,mn; 
bool used[1111][1111];
int go(int tx,int ty)
{
	if (used[tx][ty])
	{
		printf("%d %d\n",tx,Y);
		fflush(stdout);
		exit(0);
	}
	printf("%d %d\n",tx,ty);
	fflush(stdout);
	X=tx;Y=ty;
	scanf("%d %d %d",&a,&b,&c);
	if (!~a) exit(0);
	used[x[a]][y[a]]=0;
	used[b][c]=1; 
	x[a]=b;y[a]=c;
}
int main()
{
	scanf("%d%d",&X,&Y);
	for (int i=1;i<=666;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		used[x[i]][y[i]]=1;
	}
	while(X<500)
	{
		if (Y>500) go(X+1,Y-1);
		else if (Y<500) go(X+1,Y+1);
		else go(X+1,Y);
	}
	while(X>500)
	{
		if (Y>500) go(X-1,Y-1);
		else if (Y<500) go(X-1,Y+1);
		else go(X-1,Y);
	}
	while(Y<500)
	{
		go(X,Y+1);
	}
	while(Y>500)
	{
		go(X,Y-1);
	}
	assert(X==500 && Y==500);
	for (int i=1;i<=500;i++)
	{
		for (int j=1;j<=500;j++)
		{
			if (used[i][j]) cnt1++;
		}
	}
	for (int i=500;i<=999;i++)
	{
		for (int j=1;j<=500;j++)
		{
			if (used[i][j]) cnt2++;
		}
	}
	for (int i=1;i<=500;i++)
	{
		for (int j=500;j<=999;j++)
		{
			if (used[i][j]) cnt3++;
		}
	}
	for (int i=500;i<=999;i++)
	{
		for (int j=500;j<=999;j++)
		{
			if (used[i][j]) cnt4++;
		}
	}
	mn=min(cnt1,min(cnt2,min(cnt3,cnt4)));
	if (mn==cnt1)
	{
		while(X<999)
		{
			go(X+1,Y+1);
		}
	}
	else if (mn==cnt2)
	{
		while(Y<999)
		{
			go(X-1,Y+1);
		}
	}
	else if (mn==cnt3)
	{
		while(X<999)
		{
			go(X+1,Y-1);
		}
	}
	else
	{
		while(X>1)
		{
			go(X-1,Y-1);
		}
	}
	return Accepted;
}