#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int k,a,b;

int main()
{
    k=read();a=read();b=read();
    if(a<k&&b<k) return 0*puts("-1");
    if(a<k&&b%k!=0) return 0*puts("-1");
    if(b<k&&a%k!=0) return 0*puts("-1");  
    cout<<a/k+b/k;
	return 0;
}