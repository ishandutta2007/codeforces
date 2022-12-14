#include<iostream>
#include<cstdio>
#define MN 7900
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
int a[MN+5][MN+5],res[MN+5];
int R,a1,a2,a3,a4,cnt,id[105][105],ans;
inline int&ID(int x,int y){return id[x+R+1][y+R+1];}
void Gauss()
{
	for(int i=1;i<=cnt;++i)
	{
		for(int j=i;j<=cnt&&j<=i+100;++j) if(a[j][i])
		{
			if(j!=i) 
			{
				for(int k=i;k<=cnt&&k<=i+100;++k) swap(a[i][k],a[j][k]);	
				swap(a[i][cnt+1],a[j][cnt+1]);
			}
			break;
		}
		if(!a[i][i])continue;
		int Inv=pow(a[i][i],mod-2);
		for(int j=i+1;j<=cnt&&j<=i+100;++j) if(a[j][i])
		{
			int t=1LL*Inv*a[j][i]%mod;
			for(int k=i;k<=cnt&&k<=i+100;++k)
				a[j][k]=(a[j][k]-1LL*a[i][k]*t%mod+mod)%mod;
			a[j][cnt+1]=(a[j][cnt+1]-1LL*a[i][cnt+1]*t%mod+mod)%mod;
		}
	}
	for(int i=cnt;i;--i)
	{
		int t=a[i][cnt+1];
		for(int j=i+1;j<=cnt&&j<=i+100;++j) t=(t-1LL*a[i][j]*res[j]%mod+mod)%mod;
		res[i]=1LL*t*pow(a[i][i],mod-2)%mod;
		ans=(ans+res[i])%mod;
	}
}
int main()
{
	R=read();a1=read();a2=read();a3=read();a4=read();int inv=pow(a1+a2+a3+a4,mod-2);
	for(int i=-R;i<=R;++i)for(int j=-R;j<=R;++j) if(i*i+j*j<=R*R) ID(i,j)=++cnt,a[cnt][cnt]=1;
	a[ID(0,0)][cnt+1]=1;
	for(int i=-R;i<=R;++i) for(int j=-R;j<=R;++j) if(i*i+j*j<=R*R)
	{
		if(ID(i-1,j)) a[ID(i-1,j)][ID(i,j)]=mod-1LL*a1*inv%mod;
		if(ID(i,j-1)) a[ID(i,j-1)][ID(i,j)]=mod-1LL*a2*inv%mod;
		if(ID(i+1,j)) a[ID(i+1,j)][ID(i,j)]=mod-1LL*a3*inv%mod;
		if(ID(i,j+1)) a[ID(i,j+1)][ID(i,j)]=mod-1LL*a4*inv%mod;
	}
	Gauss();cout<<ans;
	return 0;
}