#include<iostream>
#include<cstdio>
using namespace std;
long long f[50][2],s[50],S[50],a,b,A,B;
int num1,num2;
int main()
{
	cin>>a>>b;
	for(A=a;a;a>>=1) s[++num1]=a&1;
	for(B=b;b;b>>=1) S[++num2]=b&1;
	f[0][0]=1;
	for(int i=1,Sum;i<=max(num1,num2);++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				if(((Sum=k+(S[i]^k)+j)&1)==s[i])
					f[i][Sum>>1]+=f[i-1][j];
	printf("%lld\n",f[max(num1,num2)][0]-2*(A==B));
	return 0;
}