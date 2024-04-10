#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 100001
int T,N,a[MAXN],cnt[MAXN],cnt2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int ans=0,sum=0;vector<int>val;
		FOR(i,N,1)
		{
			vector<int>tmp;for(auto j:val)sum=(sum+1ll*cnt[j]*((a[i]-1)/j))%P;ans=(ans+sum)%P;
			for(auto j:val){if(!cnt2[a[i]/((a[i]+j-1)/j)])tmp.push_back(a[i]/((a[i]+j-1)/j));cnt2[a[i]/((a[i]+j-1)/j)]+=cnt[j];cnt[j]=0;}
			if(!cnt2[a[i]])tmp.push_back(a[i]);cnt2[a[i]]++;
			for(auto j:tmp)cnt[j]=cnt2[j],cnt2[j]=0;val=tmp;
		}
		cout<<ans<<'\n';
	}
	return 0;
}