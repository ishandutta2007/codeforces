#include<bits/stdc++.h>
using namespace std;
long long n,i,ii,a[1001000],to,te,k,ta,nn;
int main()
{
	cin>>n>>k;
	ii=0;
	for(i=0;i<n;i++)
	{
		cin>>ta;
		if(ta>0)
		{
			a[ii]=ta;
			ii++;
		}
	}
	nn=n;
	n=ii;
	for(i=0;i<n;i++)
	{
		to=to+(a[i]/10);
		a[i]=10-(a[i]%10);
	}
	sort(a,a+n);
	i=0;
	while((k>=0)&&(i<n))
	{
		if(k-a[i]>=0)
		{
			to++;
		}
		k=k-a[i];
		i++;
	}
	//cout<<k<<endl;
	if(k>=0)
	{
		to=to+(k/10);
	}
	cout<<min(to,nn*10)<<endl;
	return 0;
}