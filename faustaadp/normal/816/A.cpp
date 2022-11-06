#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll h,m,hs;
bool pal()
{
	ll h1,h2,m1,m2;
	h1=h/10;
	h2=h%10;
	m1=m/10;
	m2=m%10;
	if(h1==m2&&h2==m1)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%I64d:%I64d",&h,&m);
	while(1)
	{
		if(pal())
		{
			cout<<hs<<endl;
			return 0;
		}
		hs++;
		if(h==23&&m==59)
		{
			h=0;
			m=0;
		}
		else
		if(m==59)
		{
			h++;
			m=0;
		}
		else
		{
			m++;
		}
	}
}