#include <iostream>
#include <string>
using namespace std;
long long n, m ,k[105], i, j, ans, rt[4000], kl, mt[4000], det;
char s;
string a6, t2;
int main()
{
	cin>>a6;
	cin>>t2;
	n=a6.length();
	m=t2.length();
	for(i=1; i<=n; i++)
	{
		s=a6[i-1];
		kl=s-'0'+1;
		mt[kl]++;
	}
	for(i=1; i<=m; i++)
	{
		s=t2[i-1];
		kl=s-'0'+1;
		rt[kl]++;
	}
	for(i=0; i<=4000; i++)
	{
		if(mt[i]==0)
		{
			if(rt[i]>0)
			{
				det++;
			}
		}
		ans=ans+min(mt[i], rt[i]);
	}
	if(det>0)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}



	

}