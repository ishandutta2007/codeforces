#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long t[N],x[N],f[N];bool g[N];
long long D(int a,int b){return std::abs(x[a]-x[b]);}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>t[i]>>x[i];
	memset(f,-63,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;++i)
	{
		if(D(i-1,i)<=f[i-1]+t[i]-t[i-1])f[i]=min(t[i]-t[i-1],f[i-1]+t[i]-t[i-1]-D(i-1,i));
		if(g[i-1]&&D(i-2,i)<=t[i]-t[i-2])f[i]=max(f[i],std::min(t[i]-t[i-1],t[i]-t[i-2]-D(i-2,i)));
		for(int j=i-2;j>=0&&!g[i];--j)
		{
			g[i]|=(f[j]>=0&&max(f[j],D(j,i))+D(i,j+1)<=f[j]+t[j+1]-t[j])||(g[j]&&max(t[j]-t[j-1],D(j-1,i))+D(i,j+1)<=t[j+1]-t[j-1]);
			if(t[j+1]-t[j]<D(j,j+1)) break;
		}
	}
	return puts((f[n]>=0||g[n])?"YES":"NO"),0;
}