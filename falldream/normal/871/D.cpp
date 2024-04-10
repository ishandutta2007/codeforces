#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 10000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool b[MN+5];
int n,s[MN/5],num=0,mn[MN+5],mu[MN+5],size,N[MN+5];
long long ans=0,res=0,res2=0,res3=0,num3=0;
int main()
{
	n=read();mu[1]=1;size=sqrt(n);
	for(int i=2;i<=n;++i)
	{
		if(!b[i]) {s[++num]=i,mu[i]=-1,mn[i]=i;if(i>n>>1)++num3;}
		for(int j=1;s[j]*i<=n;++j)
		{
			b[s[j]*i]=1;mn[s[j]*i]=min(mn[i],s[j]);
			if(i%s[j]==0)break;
			mu[s[j]*i]=-mu[i];
		}
		mu[i]+=mu[i-1];++N[mn[i]];
	}
	for(int i=1,last;i<=n;i=last+1)
	{
		last=n/(n/i);	
		res+=1LL*(mu[last]-mu[i-1])*(n/i)*(n/i); 
	}
//	printf("res=%d\n",res);
	ans+=(1LL*n*n-(res+n-1))/2;
//	printf("%d\n",ans);
	res=(res-2*n+1)/2;
	for(int i=1;i<=n;++i) N[i]+=N[i-1];
	for(int i=1;i<=size;++i) res2+=1LL*(N[i]-N[i-1])*(N[n/i]-N[i])+1LL*(N[i]-N[i-1])*(N[i]-N[i-1]-1)/2;
//	printf("res2=%d\n",res2);
	for(int i=2;i<=n;++i)
	{
		int num1=0,num2=0;	
	//	for(int j=i;j<=n;j+=i) if(j>1)
	//		if(mn[j]<=size) ++num1;
	//		else ++num2;
		if(mn[i]>size) num1=n/i-1,num2=1;
		else num1=n/i,num2=0;
		//cout<<i<<" "<<mu[i]-mu[i-1]<<" "<<num1<<" "<<num2<<endl;
		res2+=(mu[i]-mu[i-1])*(1LL*num1*(num1-1)/2+1LL*num2*num1); 
	}
	ans+=res2*2;res3=res-res2;
//	printf("num3 = %d\n",num3);
	res3-=1LL*num3*(num3-1)/2+1LL*num3*(n-1-num3);
	ans+=res3*3;
//	cout<<res<<" "<<res2<<" "<<res3<<endl;
	cout<<ans; 
	return 0;
}