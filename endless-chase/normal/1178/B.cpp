#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
char s[2222222];
int n,lef[2222222],rig[2222222];
long long ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<n;i++)
	{
		if (s[i]=='v' && s[i-1]=='v') lef[i]=lef[i-1]+1;
		else lef[i]=lef[i-1];
	}
	for (int i=n-2;i>=0;i--)
	{
		if (s[i]=='v' && s[i+1]=='v') rig[i]=rig[i+1]+1;
		else rig[i]=rig[i+1];
	}
	for (int i=0;i<n;i++)
	{
		if (s[i]=='o') ans+=(1ll*lef[i]*rig[i]);
	}
	printf("%lld\n",ans);
	return Accepted;
}