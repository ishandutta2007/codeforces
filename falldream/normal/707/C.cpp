#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')	{ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
long long m,n;
int main()
{
    n=read();
    m=n*n;
	if(n<=2)
	{
		cout<<"-1";
		return 0;
	}
	if(n&1)
	{
		cout<<m/2<<" "<<m/2+1;
	}
	else
	{
		m=m/2;
		cout<<(m/2-1)<<" "<<m/2+1;
	} 
    return 0;
}