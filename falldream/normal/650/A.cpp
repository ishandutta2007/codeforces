#include<iostream>
#include<cstdio>
#include<map> 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<int,int> a,b;
map<pair<int,int>,int>s;
int n;long long ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		ans+=a[x]++;
		ans+=b[y]++;	
		ans-=s[make_pair(x,y)]++;
	}
	cout<<ans;
	return 0;
}