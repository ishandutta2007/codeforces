#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get();int ans=0;
	For(j,0,29)
	{
		int cnt[2]={0,0};For(i,1,N)if(((a[i]>>j)<<j)==a[i])cnt[(a[i]>>j)&1]++;
		if(!j)ans=(ans+1ll*(pow(2,cnt[1])-1)*pow(2,cnt[0]))%P;
		else ans=(ans+1ll*(pow(2,max(cnt[1]-1,0))-1)*pow(2,cnt[0]))%P;
	}
	cout<<ans<<'\n';return 0;
}