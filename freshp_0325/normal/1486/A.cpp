#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,h[105];
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)
	{
		scanf("%lld",&n);
		for(LL i=0;i<n;++i)	scanf("%lld",&h[i]);
		for(LL i=0;i<n;++i)
		{
			if(h[i]<i)
			{
				puts("NO");
				goto fail;
			}
			LL tmp=h[i]-i;
			h[i+1]+=tmp;
			h[i]-=tmp;
		}
		puts("YES");
		fail:;
	}
	return 0;
}