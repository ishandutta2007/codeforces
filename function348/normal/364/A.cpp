#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int a;
int b[N],t[N];
char s[N];
long long ans;
int main()
{
	scanf("%d",&a);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++) t[i]=t[i-1]+s[i]-'0';
	for (int i=1;i<=n;i++)
	for (int j=0;j<i;j++)
		b[t[i]-t[j]]++;
	if (a==0)
	{
		int c1=0;
		long long c2=0,c3=0;
		for (int i=1;i<=n;i++) 
		if (s[i]=='0') c1++;else c2+=2LL*c1*(c1+1)/2*n*(n+1)/2,c3+=1LL*c1*(c1+1)/2,c1=0;
		c2+=2LL*c1*(c1+1)/2*n*(n+1)/2;
		c3+=1LL*c1*(c1+1)/2;
		ans=c2-c3*c3;
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i*i<=a;i++)
	if (a%i==0)
	{
		if (a/i<=100000) 
		if (i*i<a) ans+=2LL*b[i]*b[a/i];
			else   ans+=1LL*b[i]*b[a/i];
	}
	cout<<ans<<endl;
	return 0;
}