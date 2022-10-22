#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,M,a[MAXN],b[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get(),M=get();For(i,1,N)a[i]=get();bool flag=1;For(i,1,N)b[i]=get(),flag&=a[N-i+1]+b[i]<=M;cout<<(flag?"Yes\n":"No\n");}return 0;}