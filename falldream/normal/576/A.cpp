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
int n,Ans[1005],ans=0;
int main()
{
	n=read();
	for(int i=2;i<=n;++i)
	{
		int flag=1;
		for(int j=2;j<i;++j) if(i%j==0) flag=0;
		if(flag){for(int t=i;t<=n;t*=i) Ans[++ans]=t;}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);
	return 0;
}