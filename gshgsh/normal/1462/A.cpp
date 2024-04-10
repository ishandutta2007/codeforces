#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 301
int T,N,a[MAXN],b[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){N=get();int l=1,r=N;For(i,1,N)a[i]=get();For(i,1,N)b[i]=i&1?a[l++]:a[r--];For(i,1,N)put(b[i]),putchar(' ');putchar('\n');}return 0;}