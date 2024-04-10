#include<bits/stdc++.h>
using namespace std;
#define Output for(int i=1;i<=n;++i){for(int j=1;j<=m;++j)	cout<<a[i][j]<<' ';cout<<endl;}
int a[105][105],b[105][105];
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)	for(int j=1;j<=m;++j)	cin>>a[i][j];
		if(m&1)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int p=(i-1)*m+j;
				p&=1;
				if(p)
				{
					if(a[i][j]%2==0)	++a[i][j];
				}
				else
				{
					if(a[i][j]&1)	++a[i][j];
				}
			}
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					int p=i+j;
				p&=1;
				if(p)
				{
					if(a[i][j]%2==0)	++a[i][j];
				}
				else
				{
					if(a[i][j]&1)	++a[i][j];
				}
				}
			}
		}
		Output;
	}
	return 0;
}