#include<iostream>
#include<cstdio>
#include<cstring>
#define db double
#define N 100010
using namespace std;
db f[N];
int pos[N];
int main()
{
	int n;
	scanf("%d",&n);
	f[1]=1;
	for(int i=2;i<=n;i++) f[i]=f[i-1]+1*1.0/i;
//	{
//		f[i]=1,pos[i]=0;
//		for(int j=1;j<n;j++)
//		if(f[j]+(i-j)*1.0/i>f[i]) f[i]=f[j]+(i-j)*1.0/i,pos[i]=j;
//	}
	printf("%.6f",f[n]);
	return 0;
}