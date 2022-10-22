#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int N,K,a[MAXN],b[MAXN],f[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),K=get();For(i,1,N)a[i]=get(),b[i]=get();int s1=0,s2=0;For(i,1,N)s1=(s1+a[i])%K,s2=(s2+b[i])%K;
	ll sa=0,sb=0;For(i,1,N)sa+=a[i],sb+=b[i];if(s1+s2<K){cout<<sa/K+sb/K<<'\n';return 0;}f[0][0]=1;
	For(i,0,N-1){For(j,0,K-1)f[i+1][j]=f[i][j];int l=max(K-b[i+1],0),r=min(a[i+1],K-1);For(j,0,K-1)For(k,l,r)f[i+1][(j+k)%K]|=f[i][j];}
	int ans=0;For(i,K-s2,s1)ans|=f[N][i];cout<<sa/K+sb/K+ans<<'\n';
}