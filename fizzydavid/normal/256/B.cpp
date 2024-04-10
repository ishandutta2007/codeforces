#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
long long n,x,y,c;
inline long long f(long long x){return x*x+2*x+1;}
inline long long g(long long x){return (x+1)*(x+2)/2;}
long long solve(long long t)
{
	long long ans;
	ans=2*t*t+2*t+1;
	if(t>=x)ans-=f(t-x);
	if(t>=n+1-y)ans-=f(t-(n+1-y));
	if(t>=n+1-x)ans-=f(t-(n+1-x));
	if(t>=y)ans-=f(t-y);
	if(t>=n+1+x-y)ans+=g(t-(n+1+x-y));
	if(t>=n+1-y+n+1-x)ans+=g(t-(n+1-y+n+1-x));
	if(t>=n+1-x+y)ans+=g(t-(n+1-x+y));
	if(t>=x+y)ans+=g(t-(x+y));
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&x,&y,&c);
	long long l=-1,r=2*n,m;
	while(l+1<r)
	{
		m=(l+r)/2;
		if(solve(m)<c)l=m;else r=m;
	}
	cout<<r;
// 	system("pause");
	return 0;
}