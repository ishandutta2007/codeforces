#include<bits/stdc++.h>
using namespace std;
int n;
double getProb(int x)
{
	double sum=n*(n-1)*(n-2)/6;
	double ch3=x*(x-1)*(x-2)/6,ch2=(n-x)*x*(x-1)/2,ch1=(n-x)*(n-x-1)/2*0.5*x;
	return (ch3+ch2+ch1)/sum;
}
int main(){
	double p;
	scanf("%d %lf",&n,&p);
	for(int i=0;i<=n;++i)	if(getProb(i)>=p)	return printf("%d",i)&0;
}