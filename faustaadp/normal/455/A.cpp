#include<bits/stdc++.h>
using namespace std;
long long  n,hs,tp,i,ha,r;
long long d[100001],a[100001];
long long rmt(int ra)
{
//	cout<<ra<<endl;;
	if(a[ra]==0)
	{
		if(ra<=100000)
		{
			return rmt(ra+1);
		}
	}
	else
	{
		if(ra<=100000)
		{
			if(d[ra]==0)
			{
				d[ra]=max(rmt(ra+2)+a[ra],rmt(ra+1));
			}
			r=d[ra];
			return r;
		}
	}
}
int main()
{
	cin>>n;
	//n=10;
	for(i=1;i<=100000;i++)
	{
		a[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>tp;
	//	scanf("%I64d",&tp);
	//	tp=rand()%100000+1;
		a[tp]++;
	}
	for(i=1;i<=100000;i++)
	{
		d[i]=0;
		a[i]=a[i]*i;
	}
	cout<<rmt(1)<<endl;
}