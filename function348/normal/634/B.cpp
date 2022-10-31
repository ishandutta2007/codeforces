#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL s,x;
int main()
{
	cin>>s>>x;
	LL p=s-x,tmp=0,ans=1;
	if (p%2==1) ans=0;
	if(s<x) ans=0;
	for (int i=0;i<60;i++)
	{
		if ((p>>(i+1))&1) 
		{
			if ((x>>i)&1) ans=0;
			tmp+=1LL<<(i+1);
		}
		else if ((x>>i)&1) ans=ans*2,tmp+=1LL<<i;
	}
	if (s==x) ans-=2;
	if (tmp!=s) ans=0;
	cout<<ans<<endl;
	return 0;
}