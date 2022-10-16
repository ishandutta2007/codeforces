#include<bits/stdc++.h>
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
const int xx=7005;
int prim[xx];
int vis[xx];
int mu[xx];
bitset<xx>num[xx];// 
bitset<xx>ask[xx];//ask d mu 
bitset<xx>f[100005];
void pre()
{
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<=7000;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>7000)break;
			vis[prim[j]*i]=1;
			mu[prim[j]*i]=(i%prim[j]==0)?0:-mu[i];
			if(i%prim[j]==0)break;
		}
	}
	for(int i=1;i<=7000;i++)
	{
		for(int j=1;j;j++)
		{
			if(i*j>7000)break;
			num[i*j][i]=1;
			ask[i][i*j]=(mu[j]+2)&1;
		}
	}
}
int n,m;
int main(){
//	freopen("a.out","w",stdout);
	pre();
	n=read();
	m=read();
//	cout<<num[6]<<endl;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)
		{
			int x,v;
			x=read();
			v=read();
			f[x]=num[v];
		}
		if(op==2)
		{
			int x,y,z;
			x=read();
			y=read();
			z=read();
			f[x]=f[y]^f[z];
		}
		if(op==3)
		{
			int x,y,z;
			x=read();
			y=read();
			z=read();
			f[x]=f[y]&f[z];
		}
		if(op==4)
		{
			int x,v;
			x=read();
			v=read();
			cout<<(f[x]&ask[v]).count()%2;
		}
	}
	puts("");
	return 0;
}