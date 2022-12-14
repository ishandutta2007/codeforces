#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAXN 50000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'|ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int main()
{
	n=read()+1;
	puts("2");
    for(ll i=3;i<=n;i++)
    {
    	cout<<(i*(i*(i-1)-1)+2)<<endl;
    }
	return 0;
}