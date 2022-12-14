#include<iostream>
#include<cstdio>
#define MN 1000000
#define ull unsigned long long
#define mod 1000000000007LL
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char a[MN+5],b[MN+5],V[256];
int n;ull ha1,ha2,j=1;
int main()
{
	n=read()-1;
	V['W']='E';V['N']='S';V['S']='N';V['E']='W';
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;++i)
	{
		ha1=(ha1+a[n-i+1]*j)%mod;
		ha2=(ha2*23333+V[b[n-i+1]])%mod; 
		j=(j*23333)%mod;
		if(ha1==ha2) return 0*puts("NO");
	}
	puts("YES");
	return 0;
}