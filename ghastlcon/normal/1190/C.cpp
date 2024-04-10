#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n,k;char s[maxn];
int sm[maxn];

bool one_step(char *s,int n)
{
	static int sm[maxn],i;sm[0]=0;
	for(i=1;i<=n;i++) sm[i]=sm[i-1]+(s[i]-'0');//,cerr<<s[i];cerr<<endl;
	for(i=1;i<=n-k+1;i++)
	{
		int x=sm[n]-sm[i+k-1] + sm[i-1];
		if(!x || x==n-k) return true;
	}
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif

	int i;

	scanf("%d%d%s",&n,&k,s+1);sm[0]=0;
	for(i=1;i<=n;i++) sm[i]=sm[i-1]+(s[i]-'0');

	if(one_step(s,n)) puts("tokitsukaze"),exit(0);

	static char t[maxn];

	memcpy(t,s,sizeof(s));for(i=1;i<=k;i++) t[i]='0';
	if(!one_step(t,n)) puts("once again"),exit(0);
	memcpy(t,s,sizeof(s));for(i=1;i<=k;i++) t[i]='1';
	if(!one_step(t,n)) puts("once again"),exit(0);
	memcpy(t,s,sizeof(s));for(i=n-k+1;i<=n;i++) t[i]='0';
	if(!one_step(t,n)) puts("once again"),exit(0);
	memcpy(t,s,sizeof(s));for(i=n-k+1;i<=n;i++) t[i]='1';
	if(!one_step(t,n)) puts("once again"),exit(0);

	for(i=2;i<=n-k;i++)
	{
		if(s[i-1]==s[i+k]) puts("once again"),exit(0);//just set this != s[i-1]
		if(sm[i-1] != (s[i-1]-'0')*(i-1) || sm[n]-sm[i+k-1] != (s[i+k]-'0')*(n-(i+k-1))) 
			puts("once again"),exit(0);
	}
	puts("quailty");

	return 0;
}