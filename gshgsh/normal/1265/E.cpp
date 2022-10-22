#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int N,p[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main(){N=get();For(i,1,N)p[i]=1ll*get()*pow(100,P-2)%P;int a=0,b=0;FOR(i,N,1)a=(1ll*a*p[i]+1+P-p[i])%P,b=(1ll*b*p[i]+1)%P;cout<<1ll*b*pow(1+P-a,P-2)%P<<'\n';return 0;}