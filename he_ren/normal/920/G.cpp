#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXS = (1<<7) + 5;

int n,m,d;
int p[10],pcnt=0,maxs;

bool chk(ll mid)
{
	ll cnt=0;
	for(int s=0; s<maxs; ++s)
	{
		int f=1, tmp=1;
		for(int j=0; j<pcnt; ++j)
			if((s>>j)&1)
				tmp*=p[j], f^=1;
		
		if(f) cnt += mid/tmp - n/tmp;
		else cnt -= mid/tmp - n/tmp;
	}
	return cnt>=d;
}

void solve(void)
{
	scanf("%d%d%d",&n,&m,&d);
	
	pcnt=0;
	int t=m, st=sqrt(t);
	for(int i=2; i<=st && t>1; ++i)
		if(t%i==0)
		{
			p[pcnt++]=i;
			while(t%i==0) t/=i;
		}
	if(t>1) p[pcnt++]=t;
	maxs=1<<pcnt;
	
	ll l=n+1, r=n+(ll)m*d;
	while(l<r)
	{
		ll mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}