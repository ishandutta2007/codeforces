#include<cstdio>
#include<iostream>
using namespace std;
int n,x,y;
char s[300010];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	int cnt=0;scanf("%s",s+1);
	s[n+1]='1';
	for (int i=1;i<=n;i++)
	if (s[i]=='0'&&s[i+1]!='0') cnt++;
	long long ans=0;
	if (x>y) ans=1LL*y*cnt;else 
	if (cnt>=1) ans=1LL*x*(cnt-1)+y;else ans=0;
	cout<<ans<<endl;
	return 0;
}