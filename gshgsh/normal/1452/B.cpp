#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N;ll a[MAXN],mx,sum;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){N=get(),mx=sum=0;For(i,1,N)a[i]=get(),mx=max(mx,a[i]),sum+=a[i];put(max(mx*(N-1)-sum,(sum/(N-1)+(sum%(N-1)!=0))*(N-1)-sum)),putchar('\n');}return 0;}