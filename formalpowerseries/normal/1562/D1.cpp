#include<bits/stdc++.h>
using namespace std;
int sum[300005];
char s[300005];
int n,m;
void Solve()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(i&1)	sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
		else	sum[i]=sum[i-1]+(s[i]=='+'?-1:1);
	}
	while(m-->0)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if((r-l+1)&1)	puts("1");
		else	puts(sum[r]-sum[l-1]?"2":"0");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}