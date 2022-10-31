#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
long long t, s1, s2, i, j, m, n, s81, oi[2020], secf, s, ans;
char we;
int main()
{
	cin>>n>>m;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			cin>>we;
			if(we=='G')
			{
				s81=j;
			}
			if(we=='S')
			{
				s2=j;
			}
		}
		s=s2-s81;
		if(s<0)
		{
			secf++;
		}
		if(s>0)
		{
			oi[s]++;
		}
	}
	for(i=1; i<=2008; i++)
	{
		if(oi[i]>0)
		{
			ans++;
		}
	}
	if(secf>0)
	{
	    cout<<-1;
	}
	else
	{
		cout<<ans;
	}
}