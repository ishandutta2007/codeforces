#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;

long long n,ans,ra,rb,rc,P[20][70],p[20];
int k,d[20];

void attB(int i,long long a,long long b,long long bc)
{
	if (b*b>bc) return;
	if (i==k)
	{
		long long c=bc/b;
		if (a*b+b*c+c*a<ans)
		{
			ans=a*b+b*c+c*a;
			ra=a; rb=b; rc=c;
		}
		return;
	}
	for (int j=0;j<=d[i];j++)
	{
		d[i]-=j;
		attB(i+1,a,b*P[i][j],bc);
		d[i]+=j;
	}
}

void attA(int i,long long a)
{
	if (a*a>n/a) return;
	if (i==k) 
	{
		long long bc=n/a;
		if (sqrt(bc)*2*a+bc>=ans) return;
		attB(0,a,1,bc);
		return;
	}
	for (int j=d[i];j>=0;j--)
	{
		d[i]-=j;
		attA(i+1,a*P[i][j]);
		d[i]+=j;
	}
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		n=1;
		cin >> k;
		for (int i=0;i<k;i++) 
		{
			cin >> p[i] >> d[i];
			P[i][0]=1;
			for (int j=1;j<=d[i];j++) P[i][j]=P[i][j-1]*p[i];
			n*=P[i][d[i]];
		}
		
		ans=n*4+2; ra=n; rb=1; rc=1;
		attA(0,1);
		
		cout << ans*2 << ' ' << ra << ' ' << rb << ' ' << rc << endl;
	}
}