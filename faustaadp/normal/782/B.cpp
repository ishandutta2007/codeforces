#include<bits/stdc++.h>
using namespace std;
long long n,i;
double a[1010100],v[1001010],l,r,c,ma,mi;
bool bo;
bool rmt(double ra)
{
	double d;
	bool bi;
	ma=0;
	for(i=1;i<=n;i++)
	{
		d=(abs(ra-a[i]))/v[i];
		if(ma<d)
		{
			ma=d;
			if(a[i]<ra)
				bi=0;
			else
				bi=1;
		}
	}
	mi=min(mi,ma);
	return bi;
}
int main()
{
	mi=999999999999999999;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		//a[i]=(rand()%100000)+1;
		//cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		//v[i]=(rand()%100000)+1;
		scanf("%lf",&v[i]);
		//cin>>v[i];
	}
	l=1;
	r=1000000000;
	while(l<r)
	{
	//	cout<<c<<endl;
		c=(l+r)/2;
		bo=rmt(c);
		if(bo)
		{
			l=c+0.000001;
		}
		else
		{
			r=c-0.000001;
		}
	}
	cout<<setprecision(12)<<mi<<endl;
}