#include<cstdio>
#include<iostream>
using namespace std;
int n;
char s[10];
int f[1<<24];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int a=s[0]-'a',b=s[1]-'a',c=s[2]-'a';
		f[1<<a]++,f[1<<b]++,f[1<<c]++;
		f[(1<<a)|(1<<b)]--,f[(1<<a)|(1<<c)]--,f[(1<<b)|(1<<c)]--;
		f[(1<<a)|(1<<b)|(1<<c)]++;
	}
	for (int i=0;i<24;i++)
	for (int j=0;j<(1<<24);j++)
	if ((j>>i)&1) f[j]=f[j]+f[j-(1<<i)];
	int ans=0;
	for (int i=0;i<(1<<24);i++) ans^=f[i]*f[i];
	cout<<ans<<endl;
	return 0;
}