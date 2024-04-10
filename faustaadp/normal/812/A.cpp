#include<bits/stdc++.h>
using namespace std;
int i,j;
bool b,a[1010][1010];
int main()
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			cin>>a[i][j];
		}
	}
	b=1;
	for(i=1;i<=4;i++)
	{
		if(a[i][4]==1)
		{
			for(j=1;j<=3;j++)
			{
				if(a[i][j]==1)
					b=0;
			}
			if(i==1)
			{
				if(a[2][1]||a[3][2]||a[4][3])
					b=0;
			}
			else
			if(i==2)
			{
				if(a[1][3]||a[3][1]||a[4][2])
					b=0;
			}
			else
			if(i==3)
			{
				if(a[1][2]||a[2][3]||a[4][1])
					b=0;
			}
			else
			{
				if(a[1][1]||a[2][2]||a[3][3])
					b=0;
			}
		}
	}
	if(b==1)	cout<<"NO\n";
	else	cout<<"YES\n";
}