#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define eps 1e-9
#define MAXN 71
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();if(N==1||N==2){cout<<"0\n";continue;}
		int ans=N-2;
		For(i,1,N)For(j,i+1,N)
		{
			double d=(a[j]-a[i])*1.0/(j-i),a0=a[i]-d*i;
			int sum=0;For(k,1,N)if(abs(a0+d*k-a[k])<eps)sum++;
			ans=min(ans,N-sum);
		}
		cout<<ans<<'\n';
	}
}