#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,a[MAXN],f[MAXN][320];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int ask(int x,int v){if(x>N)return 0;if(1ll*v*v<=N&&f[x][v])return f[x][v];int ans=ask(x+a[x]+v,v)+1;if(1ll*v*v<=N)f[x][v]=ans;return ans;}
int main(){N=get();For(i,1,N)a[i]=get();M=get();For(i,1,M){int x=get(),v=get();put(ask(x,v)),putchar('\n');}return 0;}