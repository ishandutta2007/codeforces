#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
long long L,R;
int ans;
bool mark;
char num[10],lp[20],rp[20];
bool dfs(int n,bool l,bool r)
{
	if(n==18)return 1;
	if(l&&r)
	{
		if(lp[n]==rp[n])
		{
			if(!num[lp[n]])return 0;
			--num[lp[n]];
			bool f=dfs(n+1,1,1);
			++num[lp[n]];
			return f;
		}
		else
		{
			for(int i=lp[n]+1;i<rp[n];++i)
				if(num[i])
					return 1;
			if(num[lp[n]])
			{
				--num[lp[n]];
				bool f=dfs(n+1,1,0);
				++num[lp[n]];
				if(f)return 1;
			}
			if(!num[rp[n]])return 0;
			--num[rp[n]];
			bool f=dfs(n+1,0,1);
			++num[rp[n]];
			return f;
		}
	}
	else if(l)
	{
		for(int i=lp[n]+1;i<=9;++i)
			if(num[i])
				return 1;
		if(!num[lp[n]])return 0;
		--num[lp[n]];
		bool f=dfs(n+1,1,0);
		++num[lp[n]];
		return f;
	}
	else
	{
		for(int i=0;i<rp[n];++i)
			if(num[i])
				return 1;
		if(!num[rp[n]])return 0;
		--num[rp[n]];
		bool f=dfs(n+1,0,1);
		++num[rp[n]];
		return f;
	}
}
void pfs(int n,int last)
{
	if(n==10)
	{
		if(!last && dfs(0,1,1))
		{
			if(num[0]==17&&num[1]==1)mark=1;
			else ++ans;
		}
		return;
	}
	pfs(n+1,last);
	for(int i=1;i<=last;++i)
	{
		++num[n];
		pfs(n+1,last-i);
	}
	num[n]-=last;
}
int main()
{
	scanf("%lld%lld",&L,&R);
	if(R==1e18)
	{
		if(L==R)
		{
			puts("1");
			return 0;
		}
		mark=1;
		--R;
	}
	for(int i=0;i<=17;++i)
		lp[i]=L%10,L/=10;
	for(int i=0;i<=17;++i)
		rp[i]=R%10,R/=10;
	reverse(lp,lp+17+1);
	reverse(rp,rp+17+1);
	pfs(0,18);
	printf("%d\n",ans+mark);
}