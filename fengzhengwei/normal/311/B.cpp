#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=100005;
int n,m,p,q[xx];
ll jl[xx],v[xx],f[xx][105],sum[xx];
ll B(int x,int j){return f[x][j-1]+sum[x];}
signed main(){
	n=read(),m=read(),p=read();
	if(p>=m)return puts("0"),0;
	for(int i=2;i<=n;i++)jl[i]=jl[i-1]+read();
	for(int i=1;i<=m;i++)
	{
		int h=read(),t=read();
		v[i]=t-jl[h];
	}
	sort(v+1,v+m+1);
	
	for(int i=1;i<=m;i++)sum[i]=sum[i-1]+v[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int j=1;j<=p;j++)
	{
		int l=1,r=1;q[l]=0;
		for(int i=1;i<=m;i++)
		{
			while(l<r&&f[q[l+1]][j-1]-f[q[l]][j-1]+sum[q[l+1]]-sum[q[l]]<=v[i]*(q[l+1]-q[l]))l++;
			f[i][j]=f[q[l]][j-1]+v[i]*(i-q[l])-(sum[i]-sum[q[l]]);
			while(l<r&&1.0l*(B(i,j)-B(q[r],j))*(q[r]-q[r-1])<=1.0l*(B(q[r],j)-B(q[r-1],j))*(i-q[r]))r--;
			q[++r]=i;
		}
	}
	cout<<f[m][p]<<'\n';
	return 0;
}