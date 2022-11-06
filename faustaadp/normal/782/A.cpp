#include<bits/stdc++.h>
using namespace std;
long long n,i,t,hs,ma;
bool b[101010];
int main()
{
	cin>>n;
	for(i=1;i<=2*n;i++)
	{
		cin>>t;
		if(!b[t])
		{
			hs++;
			ma=max(hs,ma);
			b[t]=!b[t];
		}
		else
		{
			hs--;
			ma=max(hs,ma);
			b[t]=!b[t];
		}
	}
	cout<<ma<<endl;
}