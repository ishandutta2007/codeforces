#include<bits/stdc++.h>
using namespace std;
long long n,i,l,ll;
int main()
{
	cin>>n;
	l=sqrt(n);
	for(i=l;i>=1;i--)
	{
		if(n%i==0)
		{
			cout<<i<<" "<<n/i<<endl;
			break;
		}
	}
	return 0;
}