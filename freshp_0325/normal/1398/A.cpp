#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[50005];
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>a[i];
		LL p=a[1]+a[2];
		for(int i=3;i<=n;++i)
		{
			if(a[i]>=p)
			{
				cout<<1<<' '<<2<<' '<<i<<endl;
				goto suc;
			}
		}
		cout<<-1<<endl;
		suc:;
	}
	return 0;
}