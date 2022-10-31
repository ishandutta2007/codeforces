#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int n;char s[maxn];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif

	int i,Sum=0,R=-1;

	scanf("%d%s",&n,s);
	for(i=0;i<n;i++)
	{
		Sum+=(s[i]=='(' ? 1 : -1);
		if(Sum<0) R=max(R,i);
		if(Sum<=-2) puts("No"),exit(0);
	}

	if(Sum!=0) puts("No"),exit(0);
	if(R==-1) puts("Yes"),exit(0);

	for(i=R;i<n;i++) if(s[i]=='(') puts("Yes"),exit(0);

	puts("No");
	
	return 0;
}