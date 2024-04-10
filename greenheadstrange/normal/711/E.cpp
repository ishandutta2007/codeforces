#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
long long mode=1000003;
long long psa,psb;
void getps(long long x,long long y)
{	
	if(y==0) 
	{
			psa=1,psb=0;
			return;
	}
	else getps(y,x%y);
	long long bpsb=psb;
	psb=psa-(x/y)*psb;
	psa=bpsb;
	return ;
}

long long back(long long a)
{	//a 
	getps(a,mode);
	return psa;
} 

long long power(long long n,long long m)
{
	 if(m==-1) return back(n);
	 if(m==0) return 1;
	 long long now=power(n,m/2);
	 now=now*now;
	 now%=mode;
	 if(m%2) now*=n;
	 now%=mode;
	 return now;
}

long long n,k;
long long divs=0;
long long A,B;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	if(n<64)
	{
		long long pn=1;
		for(long long i=0;i<n;i++) pn*=2;
		if(pn<k)
		{
			printf("1 1\n");
			return 0;
		 } 
	}
	long long nowsum=2;
	long long nnums=1;
	for(;(nnums<=n && nowsum<=k);)
	{
		divs+=(k-1)/nowsum;
		divs++;
		nowsum*=2;
		nnums++;
	}
	if(nnums<n) divs+=(n-nnums+1);
	
	long long a=power(2,((n%(mode-1))*(k%(mode-1)))%(mode-1));
	long long b=power(2,divs);
	long long ns=power(2,n);
	
	if(ns<k) A=0;
	else 
	{
		long long ans=1;
		for(long long i=0;i<k;i++) ans*=(ns-i),ans%=mode;
		A=ans*back(b); 
	}
	
	B=a*back(b);
	A=B-A;
	A%=mode,B%=mode;
	if(A<0) A+=mode;
	if(B<0) B+=mode;
	printf("%I64d %I64d\n",A,B);
	return 0;
}