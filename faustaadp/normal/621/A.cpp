#include<bits/stdc++.h>
using namespace std;
long long n,mi,i,su,a;
int main()
{
	cin>>n;
	mi=10000000010;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a%2==1&&a<mi)
			mi=a;
		su=su+a;
	}
	if(su%2==0)
		cout<<su<<endl;
	else
		cout<<su-mi<<endl;
}