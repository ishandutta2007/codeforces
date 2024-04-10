#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M;ll K,x,a[MAXN],b[MAXN];ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),K=get(),x=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);
	For(i,2,N)if(a[i]-a[i-1]>x)b[++M]=(a[i]-a[i-1]-1)/x;sort(b+1,b+M+1);
	ll y=0;For(i,1,M)if(K>=b[i])K-=b[i],y=i;else break;cout<<M-y+1<<endl;return 0;
}