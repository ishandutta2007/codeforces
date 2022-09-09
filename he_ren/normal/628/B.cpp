#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long ll;
const int MAXN = 3e5 + 5;
const int mod=4;
using namespace std;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		s[i]-='0';
		if(s[i]%4==0) ++ans;
	}
	for(int i=2; i<=n; ++i)
	{
		if((s[i-1]*10 + s[i])%4 == 0)
			ans+=i-1;
	}
	cout<<ans;
	return 0;
}