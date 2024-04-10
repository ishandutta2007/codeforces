#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mod 1000000007
#define MAXN 100000
#define MAXL 64
#define MAXS 20
using namespace std;
int s[MAXL+5],ans=0;
char ch[MAXN+5];
ll x[100];
void work(int xx)
{
	ll sum=1;
	int j=1;
	for(int i=1;i<=MAXS;i++)
	{
		 if(xx&j)
		 {
		 	 sum=(sum*x[i])%mod;
		 }
		 j<<=1;
	}
	cout<<sum;
}

int main()
{
	x[1]=3;
	for(int i=2;i<=MAXS;i++)
	{
		x[i]=(x[i-1]*x[i-1])%mod;
	}
	for(int i=0;i<=63;i++)
	{
		int x=i;s[i]=6;
		while(x)
		{
			if(x&1) s[i]--;
			x>>=1;
		}
	}
	scanf("%s",&ch);
	for(int i=0;ch[i];i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		    ans+=s[ch[i]-'0'];
		else  if(ch[i]>='a'&&ch[i]<='z')
		    ans+=s[ch[i]-'a'+36];
		else  if(ch[i]>='A'&&ch[i]<='Z')
		    ans+=s[ch[i]-'A'+10];
		else
		     if(ch[i]=='-')
		        ans+=s[62];
		     else
		        ans+=s[63];
	}
	work(ans);
	return 0;
}