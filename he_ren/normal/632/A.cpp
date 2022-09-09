#include<cstdio>
#include<iostream>
typedef long long ll;
const int MAXN = 40 + 5;
using namespace std;

char s[MAXN][10];

int main(void)
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	ll ans=0, now=0;
	for(int i=n; i>=1; --i)
	{
		if(s[i][5])
		{
			ans+=now*p + p/2;
			now=now*2+1;
		}
		else
		{
			ans+=now*p;
			now<<=1ll;
		}
	}
	cout<<ans;
	return 0;
}