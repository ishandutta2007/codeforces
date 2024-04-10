#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],M,K,b[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int N,int*a){For(i,1,N)if(a[i]!=a[N+1-i])return 0;return 1;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int l=1,r=N;while(l<=r&&a[l]==a[r])l++,r--;
		if(l>r){cout<<"YES\n";continue;}int x=a[l],y=a[r];M=0,K=0;For(i,l,r){if(a[i]!=x)b[++M]=a[i];if(a[i]!=y)c[++K]=a[i];}
		cout<<(check(M,b)||check(K,c)?"YES\n":"NO\n");
	}
	return 0;
}