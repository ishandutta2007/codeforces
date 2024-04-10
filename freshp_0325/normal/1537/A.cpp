#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		cin>>n;
		LL sum=0;
		for(LL i=1;i<=n;++i)
		{
			LL x;cin>>x;
			sum+=x;
		}
		if(sum==n)	cout<<"0";
		else if(sum<n)	cout<<"1";
		else	cout<<sum-n;
		cout<<endl;
	}
	return 0;
}