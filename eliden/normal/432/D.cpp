#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e5;
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int p[sz];
	p[0] = -1;
	p[1] = 0;
	int j = 0;
	rep(i,2,n+1)
	{
		while(j>=0 && s[j+1-1]!=s[i-1])
			j = p[j];
		j++;
		p[i] = j;
	}
	int dp[sz];
	rep(i,1,n+1)
		dp[i]=1;
	for(int i=n;i>0;--i)
		dp[p[i]]+=dp[i];

	int k=0;
	int a1[sz], a2[sz];
	for(int j=n;j>0;j=p[j])
		++k;
	
	
	for(int j=n, i=k-1;j>0;j=p[j], --i)
	{
		a1[i]=j;
		a2[i]=dp[j];
	}
	printf("%d\n",k);
	rep(i,0,k)
		printf("%d %d\n",a1[i],a2[i]);
}