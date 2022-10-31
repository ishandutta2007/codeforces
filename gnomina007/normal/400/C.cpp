#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
long long t, s1, s2, i, j, sl, sum[105], kz, sett, kl, amesn, m, x, y, z, p, n , q1[100005], q2[100005], a, b, a0, b0,xa, ya, za, m1, n1, u;
int main()
{
	cin>>n>>m>>x>>y>>z>>p;
	for(i=1; i<=p; i++)
	{
		cin>>a>>b;
		q2[i]=n+1-a;
		q1[i]=b;
	}
	for(i=1; i<=p; i++)
	{
		a=q1[i]; 
		b=q2[i];
		m1=m;
		n1=n;
		xa=x%4;
		for(j=1; j<=xa; j++)
		{
			a0=a;
			b0=b;
			a=b0;
			b=m1+1-a0;
			u=m1;
			m1=n1;
			n1=u;

		}
		ya=y%2;
		for(j=1; j<=ya; j++)
		{
			a=m1+1-a;
		}
		za=z%4;
		for(j=1; j<=za; j++)
		{
			a0=a; 
			b0=b;
			a=n1+1-b0;
			b=a0;
			u=m1;
			m1=n1;
			n1=u;
		}
		cout<<n1+1-b<<' '<<a<<endl;
	}
}