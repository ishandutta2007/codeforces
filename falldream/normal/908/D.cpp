#include<bits/stdc++.h>
#define MN 1000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5][MN+5],K,pa,pb,s,P,ans;
inline int pow(int x,int k)
{
	int res=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) res=1LL*res*x%mod;
	return res;	
}
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
	K=read();pa=read();pb=read();s=pa+pb;
	pa=1LL*pa*pow(s,mod-2)%mod;pb=1LL*pb*pow(s,mod-2)%mod;
	f[1][0]=1;P=1LL*pa*pow(mod+1-pa,mod-2)%mod;
	for(int i=1;i<=K;++i)
		for(int j=0;j<K;++j) if(f[i][j])
		{
			if(i+j<K)
			{
				R(f[i+1][j],1LL*f[i][j]*pa%mod);
				R(f[i][j+i],1LL*f[i][j]*pb%mod);
			}
			else ans=(ans+1LL*f[i][j]*(i+j+P))%mod;
		}
	printf("%d\n",ans);
	return 0;
}