#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define P 1000000007
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main(){int T=get();while(T--){ll x=get();cout<<((x/2%P+1)*(x/4%P+1)%P-x/4%P*(x/4%P+1)%P+P)%P<<'\n';}}