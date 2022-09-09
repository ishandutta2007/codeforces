#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXK = 4 + 5;

int p[MAXK];

inline bool chk(int n)
{
	for(int i=1; i<=n; ++i)
		if(p[i]==i) return 0;
	return 1;
}

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	ll ans=1;
	for(int i=1; i<=k; ++i)
	{
		for(int j=1; j<=i; ++j) p[j]=j;
		int cnt=0;
		do cnt+=chk(i); while(next_permutation(p+1,p+i+1));
		
		ll c=1;
		for(int j=n-i+1; j<=n; ++j) c*=(ll)j;
		for(int j=1; j<=i; ++j) c/=(ll)j;
		
		ans += c*cnt;
	}
	cout<<ans;
	return 0;
}