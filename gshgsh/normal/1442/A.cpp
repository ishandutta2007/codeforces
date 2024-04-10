#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 30001
int T,N,a[MAXN],b[MAXN],c[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get();For(i,1,N)a[i]=get();bool flag=1;b[1]=0,c[1]=a[1];For(i,2,N)c[i]=min(c[i-1],a[i]-b[i-1]),b[i]=a[i]-c[i],flag&=c[i]>=0;cout<<(flag?"YES\n":"NO\n");}return 0;}