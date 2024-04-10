#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
long long a,b,c,ans=5223372036854775807,maxn;
long long mint(long long a,long long b)
{
	if(a<b)return a;
	else return b;
}
long long maxt(long long a,long long b)
{
	if(a>b)return a;
	else return b;
}
long long f(void)
{
	maxn=maxt(maxt(a,b),c);
	return maxn-a+maxn-b+maxn-c;
}
int main()
{
	cin>>a>>b>>c;
	ans=mint(ans,f());
	a--,ans=mint(ans,f());
	a+=2,ans=mint(ans,f());
	a--,b--,ans=mint(ans,f());
	b+=2,ans=mint(ans,f());
	b--,c--,ans=mint(ans,f());
	c+=2,ans=mint(ans,f());
	cout<<ans<<"\n";
	return 0;
}