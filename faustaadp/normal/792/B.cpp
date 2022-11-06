#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[101010],tt,nn,ti;
bool b[101010];
int main()
{
	cin>>n>>k;
	nn=n;
	for(i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	tt=0;
	b[0]=1;
	for(i=1;i<=k;i++)
	{
		a[i]=(a[i]-1)%nn+1;
		tt=(tt-1)%n+1;
		while(b[tt]==1)
		{
			tt++;
			tt=(tt-1)%n+1;
		}
		while(a[i]>0)
		{
			tt++;
			tt=(tt-1)%n+1;
			if(b[tt]==0)
			{
				//cout<<tt<<"-";
				a[i]--;
			}
		}
		tt=(tt-1)%n+1;
		//cout<<endl;
		b[tt]=1;
		if(i<k)
			cout<<tt<<" ";
		else
			cout<<tt<<endl;
		nn--;
	}
}