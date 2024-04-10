#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,a[MAXN];bool vis[MAXN];int GCD(int a,int b){return b?GCD(b,a%b):a;}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),vis[i]=0;int x=0;For(i,1,N)if(a[i]>a[x])x=i;cout<<a[x]<<' ';vis[x]=1;int y=a[x];
		For(i,2,N)
		{
			int k=1;while(vis[k])k++;
			For(j,1,N)if(!vis[j]&&GCD(y,a[j])>GCD(y,a[k]))k=j;
			cout<<a[k]<<' ';y=GCD(y,a[k]);vis[k]=1;
		}
		cout<<endl;
	}
	return 0;
}