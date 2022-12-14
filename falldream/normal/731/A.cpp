#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 2000000000
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[105];
int ans=0;
int main()
{
	cin.getline(s,105);
	ans+=min(abs(s[0]-'a'),26-abs(s[0]-'a'));
	for(int i=1;s[i];i++)
	{
		ans+=min(abs(s[i]-s[i-1]),26-abs(s[i-1]-s[i]));
	}
	cout<<ans;
	return 0;
}