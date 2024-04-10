#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 100001
int N,a[MAXN];ll ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),ans+=a[i]-1;sort(a+1,a+N+1);
	For(i,2,1000000000){bool flag=1;ll sum=a[1]-1,x=1;For(j,2,N){x*=i;if(x-a[j]>ans){flag=0;break;}sum+=abs(x-a[j]);}if(flag)ans=min(ans,sum);if(!flag)break;}
	cout<<ans<<'\n';return 0;
}