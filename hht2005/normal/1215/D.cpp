#include<bits/stdc++.h>
using namespace std;
char s[200010];
int main() {
	int n,sum=0,L=0,R=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n/2;i++)
		if(s[i]=='?')L++;
		else sum+=s[i]^48;
	for(int i=n/2+1;i<=n;i++)
		if(s[i]=='?')R++;
		else sum-=s[i]^48;
	int l=sum+(L-R)/2*9,r=sum-(R-L)/2*9;
	if(l>=0&&r<=0)puts("Bicarp");
	else puts("Monocarp");
	return 0;
}