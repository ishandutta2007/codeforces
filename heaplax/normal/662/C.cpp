#include<bits/stdc++.h>
#define N 1<<20
using namespace std;
char s[N];
int n,m,a[N];
long long b[N],c[N];
void fwt(long long x[],int n,int f)
{
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;++k)
			{
				long long l=x[j+k],r=x[i+j+k];
				x[j+k]=l+r,x[i+j+k]=l-r;
				if(!~f)x[j+k]/=2,x[i+j+k]/=2;
			}
}
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			a[j]<<=1,a[j]+=s[j]-'0';
	}	
	for(int i=1;i<=m;++i)++b[a[i]];
	int e=1<<n;
	for(int i=0;i<e;++i)c[i]=c[i>>1]+(i&1);
	for(int i=0;i<e;++i)c[i]=min(c[i],c[(~i)&(e-1)]);
	fwt(b,e,1);fwt(c,e,1);
	for(int i=0;i<e;++i)b[i]*=c[i];
	fwt(b,e,-1);
	cout<<*min_element(b,b+e);
}