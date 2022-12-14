#include<iostream>
#include<cstdio>
#define MN 100000
#define MK 60
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,X[MN+5],Y[MN+5];
double eb=0,eS=0,pw[105];
long long Cross(int i,int j){return 1LL*X[i]*Y[j]-1LL*X[j]*Y[i];}
inline int abs(int x){return x<0?-x:x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	n=read();pw[0]=1;
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read();
	X[0]=X[n];Y[0]=Y[n];
	for(int i=0;i<n;++i) eS+=Cross(i,i+1);
	if(eS<0) eS=-eS;eS/=2;
	for(int i=1;i<=100;++i) pw[i]=pw[i-1]*2;
	for(int i=1;i<=n;++i)
	{
		long long S=0;
		for(int j=1;j<=min(MK,n-1);++j)
		{
			int k=(i+j-1)%n+1;S+=Cross(k-1,k)+Cross(k,i);double p;
			if(n<=100) p=(pw[n-j-1]-1)/(pw[n]-1-n-1LL*n*(n-1)/2);
			else p=1/pw[j+1];
			eS-=p*max(S,-S)/2;eb+=p*gcd(abs(X[i]-X[k]),abs(Y[i]-Y[k]));
			S-=Cross(k,i);
		}
	}
	printf("%.10lf\n",eS-eb/2+1); 
	return 0;
}