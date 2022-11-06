#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
char s[N];
int n,m;
ll ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) ans+=1ll*n*(m-1)*(int)(s[i]!=s[i-1]);
	int l=1;
	for(int i=2;i<=n;i++)
	if(l==1) l+=s[i]!=s[i-1];
	else if(s[i]==s[i-2]) l++;
	else ans-=l*(l-1)/2,l=1+(s[i]!=s[i-1]);
	ans-=1ll*l*(l-1)/2;
	printf("%lld\n",ans);
	return 0;
}