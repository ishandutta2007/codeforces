#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long ans=-1e18;int best=0;
int main()
{
	int a=read(),b=read();
	if(!a) 
	{
		printf("%lld\n",-1LL*b*b);	
		for(int i=1;i<=b;++i) printf("x");
	}
	if(!b)
	{
		printf("%lld\n",1LL*a*a);
		for(int i=1;i<=a;++i) printf("o");	
	}
	if(!a||!b) return 0;
	for(int i=1;i<=min(a+1,b);++i)
	{
		int j=b/i,num=b-j*i;
	//	cout<<j<<" "<<num<<endl;
		long long res=-1LL*j*j*(i-num)-1LL*(j+1)*(j+1)*num;
		int left=a-i+1;
		if(i==1) res+=1LL*a*a;
		else res+=1LL*(left+1)*(left+1)+i-2;
		if(res>ans) ans=res,best=i;
	//	cout<<i<<" "<<res<<endl;
	}
	printf("%lld\n",ans,best);
	int i=best,j=b/i,num=b-j*i,left=a-i+1;
	for(int ii=1;ii<=best;++ii)
	{
		for(int jj=1;jj<=j+(ii<=num);++jj) printf("x");
		if(ii!=best) printf("o");
		if(ii==1&&ii!=best) for(int jj=1;jj<=left;++jj) printf("o");
	}
	if(best==1) for(int jj=1;jj<=left;++jj) printf("o");
	return 0;
}