#include<bits/stdc++.h>
using namespace std;
long long n,i,tx,hs,m,xx[1010101],yy[1010101];
bool b;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tx;
		hs=hs+tx;
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>xx[i]>>yy[i];
	}
	for(i=1;i<=m;i++)
	{
		if(xx[i]<=hs&&hs<=yy[i])
		{
			b=1;
			cout<<hs<<endl;
			break;
		}
		if(xx[i]>=hs)
		{
			b=1;
			cout<<xx[i]<<endl;
			break;
		}
	}
	if(b==0)
		cout<<-1<<endl;
}