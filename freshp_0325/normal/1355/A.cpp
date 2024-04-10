#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL add(LL x)
{
	LL minn=10,maxn=-1;
	while(x)	minn=min(minn,x%10),maxn=max(maxn,x%10),x/=10;
	return maxn*minn;
}
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		LL a,k;
		cin>>a>>k;
		--k;
		for(LL i=1;i<=k;++i)
		{
			LL ad=add(a);
			if(ad==0)	break;
			a+=ad;
		}
		cout<<a<<endl;
	}
	return 0;
}