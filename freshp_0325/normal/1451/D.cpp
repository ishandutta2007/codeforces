#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL st[200010];
int main(){
	int T;
	scanf("%d",&T);
	for(LL i=1;i<=200009;++i)
	{
		if(i&1)
		{
			LL sr=(i+1)>>1;
			st[i]=sr*sr+(sr-1)*(sr-1);
		}
		else	st[i]=i*i/2;
	}
	while(T-->0)
	{
		LL d,k;
		scanf("%lld %lld",&d,&k);
		for(LL i=1;i<=200009;++i)
		{
			if(st[i]*k*k>d*d)
			{
				puts(i&1?"Utkarsh":"Ashish");
				break;
			}
		}
	}
	return 0;
}