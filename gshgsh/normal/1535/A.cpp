#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a,b,c,d;int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--)cin>>a>>b>>c>>d,cout<<(min(a,b)>max(c,d)||max(a,b)<min(c,d)?"NO\n":"YES\n");return 0;}