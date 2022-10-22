#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a,b,c,s;int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--)s=a=get(),s+=b=get(),s+=c=get(),cout<<(s%9==0&&min(a,min(b,c))>=s/9?"YES\n":"NO\n");return 0;}