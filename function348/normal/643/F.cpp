#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned int UI;
const int N=200;
UI C[N];
int n,p,q;
UI ans;
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	p=min(p,n-1);
	UI k1=0,k2=1;
	for (int i=0;i<=p;i++)
	{
//		C(n,i);
		C[i]=k2<<k1;
		UI tmp,t2=1;
		tmp=n-i;while (tmp%2==0) k1++,tmp>>=1;k2=k2*tmp;
		tmp=i+1;while (tmp%2==0) k1--,tmp>>=1;
		for (int j=0;j<=30;j++) 
		{
			k2=k2*tmp;
			tmp=tmp*tmp;
		}
	}
	for (int i=1;i<=q;i++)
	{
		UI res=0,x=1;
		for (int j=0;j<=p;j++)
		{
			res+=C[j]*x;
			x=x*i;
		}
		ans^=res*i;
	}
	cout<<ans<<endl;
	return 0;
}