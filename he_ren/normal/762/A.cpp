#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 32000000;
using namespace std;

int a[MAXN],cnt=0;

int main(void)
{
	ll n;
	int k;
	cin>>n>>k;
	
	ll sn=sqrt(n);
	for(int i=1; i<=sn; ++i)
		if(n%i==0) a[++cnt]=i;
	
	ll tot=cnt<<1ll;
	if(sn*sn==n) --tot;
	
	if(tot<k) printf("-1");
	else
	{
		if(k<=cnt) printf("%d",a[k]);
		else cout<< n / a[cnt-(k-cnt)+(sn*sn!=n)];
	}
	return 0;
}