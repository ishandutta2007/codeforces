#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 501
int T,N,M,a[MAXN][MAXN],pos[MAXN*MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){N=get(),M=get();For(i,1,N)For(j,1,M)pos[a[i][j]=get()]=i;For(i,1,N){int x=get();For(j,1,M)put(a[pos[x]][j]),putchar(' ');putchar('\n');}For(i,2,M)For(j,1,N)get();}return 0;}