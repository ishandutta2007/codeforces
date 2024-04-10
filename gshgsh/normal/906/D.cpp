#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,p[100],a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(ll a,int b,int P){ll ans=1;while(b)(b&1)&&(ans*=a,ans>=P&&(ans=ans%P+P)),a*=a,a>=P&&(a=a%P+P),b>>=1;return ans;}
int phi(int x){int ans=x;for(int i=2;i*i<=x;i++)if(x%i==0){ans=ans/i*(i-1);while(x%i==0)x/=i;}if(x>1)ans=ans/x*(x-1);return ans;}
int solve(int l,int r,int id){if(l==r+1||p[id]==1)return 1;return pow(a[l],solve(l+1,r,id+1),p[id]);}
int main()
{
	N=get(),p[0]=get();for(int i=0;p[i]>1;i++)p[i+1]=phi(p[i]);For(i,1,N)a[i]=get();M=get();
	For(i,1,M){int l=get(),r=get();cout<<solve(l,r,0)%p[0]<<'\n';}return 0;
}