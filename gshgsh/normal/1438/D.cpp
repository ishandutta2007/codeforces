#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,a[MAXN],sum;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();For(i,1,N)sum^=a[i]=get();if((N+1&1)&&sum){cout<<"NO\n";return 0;}cout<<"YES\n";
	cout<<(N-1>>1<<1)<<endl;for(int i=2;i<N;i+=2)cout<<1<<' '<<i<<' '<<i+1<<endl;for(int i=2;i<N;i+=2)cout<<1<<' '<<i<<' '<<i+1<<endl;return 0;
}