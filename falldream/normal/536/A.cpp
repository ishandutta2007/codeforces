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
int A,B,n;
inline long long S(int x){return 1LL*x*(x+1)/2;}
int main()
{
	A=read();B=read();n=read();
	for(int i=1;i<=n;++i)
	{
		int L=read(),t=read(),m=read();
		int l=L,r=1e9,mid,res=-1;
		while(l<=r)
		{
			mid=l+r>>1;
			if(1LL*(mid-L+1)*A+1LL*B*(S(mid-1)-S(L-2))<=1LL*t*m&&1LL*(mid-1)*B+A<=t) res=mid,l=mid+1;
			else r=mid-1;	
		}
		printf("%d\n",res);
	}
	return 0;
}