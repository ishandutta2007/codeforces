#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a[13242423],ta,hs,x,y,i;
bool b;
int main()
{
	cin>>n>>m>>r;
	for(i=1;i<=m;i++)
	{
		scanf("%I64d",&ta);
		//cin>>ta;
		a[ta]=1;
	}
	hs=1;
	if(a[hs]==1)
	{
		b=1;
	}
	for(i=1;i<=r;i++)
	{
		scanf("%I64d %I64d",&x,&y);
		//cin>>x>>y;
		if(b==0)
		{
			if(hs==x)
			{
				hs=y;
				if(a[hs]==1)
				{
					b=1;
				}
			}
			else
			if(hs==y)
			{
				hs=x;
				if(a[hs]==1)
				{			
					b=1;
				}
			}
		}
	}
	cout<<hs<<endl;
}