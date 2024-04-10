#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],b[MAXN],c[MAXN];
int get(){char c=getchar();int x=0;while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();For(i,1,N)c[i]=get();
		int pre=a[1],now=a[1];cout<<a[1]<<' ';For(i,2,N){if(a[i]!=now&&(i!=N||a[i]!=pre))cout<<a[i]<<' ',now=a[i];else if(b[i]!=now&&(i!=N||b[i]!=pre))cout<<b[i]<<' ',now=b[i];else cout<<c[i]<<' ',now=c[i];}cout<<endl;
	}
	return 0;
}