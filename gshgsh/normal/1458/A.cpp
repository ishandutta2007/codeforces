#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 200001
int N,M;ll a[MAXN],b[MAXN],x;
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get();x=abs(a[2]-a[1]);For(i,3,N)x=GCD(x,abs(a[i]-a[i-1]));
	For(i,1,M)b[i]=get(),put(N>1?GCD(x,a[1]+b[i]):a[1]+b[i]),putchar(' ');return 0;
}