#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
bitset<200> b[200];
int main()
{
	n=read();b[0][0]=1;b[1][1]=1;
	for(int i=2;i<=n;++i) b[i]=(b[i-1]<<1)^b[i-2];
	printf("%d\n",n);for(int i=0;i<=n;++i) printf("%d ",int(b[n][i]));puts("");
	printf("%d\n",n-1);for(int i=0;i<n;++i) printf("%d ",int(b[n-1][i]));
	return 0;
}