#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 501
int T,N,x,a[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool check(){For(i,2,N)if(a[i]<a[i-1])return 0;return 1;}
int main(){T=get();while(T--){N=get(),x=get(),ans=0;For(i,1,N)a[i]=get();For(i,1,N-1)if(a[i]>x){if(check())break;swap(a[i],x);ans++;}cout<<(check()?ans:-1)<<endl;}return 0;}