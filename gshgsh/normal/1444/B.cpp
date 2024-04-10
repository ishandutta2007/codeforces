#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 300001
int N,a[MAXN],fc[MAXN],ans;int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main(){N=get();For(i,1,N*2)a[i]=get();sort(a+1,a+N*2+1);For(i,1,N)ans=(ans+a[i+N]-a[i])%P;fc[0]=1;For(i,1,N*2)fc[i]=1ll*fc[i-1]*i%P;cout<<1ll*ans*fc[N*2]%P*pow(fc[N],P-3)%P<<endl;return 0;}