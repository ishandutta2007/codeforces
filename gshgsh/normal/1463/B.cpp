#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 51
int T,N,a[MAXN],b[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get();For(i,1,N)a[i]=get(),b[i]=0;For(i,1,N){int x=a[i];while(x)x>>=1,b[i]++;}For(i,1,N)cout<<((1<<b[i])<=1000000000&&(1<<b[i])-a[i]<a[i]-(1<<b[i]-1)?1<<b[i]:(1<<b[i]-1))<<' ';cout<<endl;}return 0;}