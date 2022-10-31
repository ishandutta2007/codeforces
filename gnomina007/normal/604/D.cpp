#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
long long  stmod(long long a, long long b, long long p)
{
	int x;
	if(b==0)
	{
		return 1;
	}
	else
	{
		if(b%2==0)
		{
			x=stmod(a, b/2, p);
			x=(x*x)%p;
			return x;
		}
		else
		{
			x=stmod(a, b-1, p);
			x=(x*a)%p;
			return x;
		}
	}
}
long long n, m, k, s[100005], t, i, j, x[100005], p, pcon, io, ans, lk, jj, pr, obr[1000005], a, b, c;
string ss;
int main()
{
	cin>>p>>k;
	pcon=1000000007;
	obr[1]=1;
	for(i=2; i<1000003; i++)
	{
		a=pcon/i;
		b=pcon%i;
		c=a*(pcon-obr[b]);
		c=c%pcon;
		obr[i]=c;
	}
	//cout<<228;
	if(k==0)
	{
		ans=1; 
		for(i=0; i<p-1; i++)
		{
			ans=(ans*p)%pcon;
		}
	}
	else
	{
		io=1;
		lk=0;
		for(i=1; i<p; i++)
		{
			io=(io*k)%p;
			//cout<<io;
			if((io%p)==1)
			{
				if(lk==0)
				{
					jj=i;
					lk=1;
				}
			}
		}
		ans=1; 
		pr=1;
		t=(p-1)/jj;
		if(k==1)
		{
		   ans=1; 
		   for(i=0; i<p; i++)
		   {
			   ans=(ans*p)%pcon;
		   }
		}
		else
		{
			for(i=1; i<=t; i++)
			{
				pr=(pr*obr[i])%pcon;
				pr=(pr*(t-i+1))%pcon;
				pr=(pr*t)%pcon;
				pr=(pr*jj)%pcon;
				ans=(ans+pr)%pcon;
			}
		}
	}
	cout<<ans;


}