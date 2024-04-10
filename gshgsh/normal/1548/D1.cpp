#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 6001
int N,cnt[4];ll ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();For(i,1,N)cnt[(get()&2)^((get()>>1)&1)]++;
	For(i,0,3)For(j,i,3)For(k,j,3)if(!((i!=j)^(i!=k)^(j!=k)))
	{
		if(i==j&&i==k)ans+=1ll*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
		else if(i==j)ans+=1ll*cnt[i]*(cnt[i]-1)/2*cnt[k];
		else if(i==k)ans+=1ll*cnt[i]*(cnt[i]-1)/2*cnt[j];
		else if(j==k)ans+=1ll*cnt[k]*(cnt[k]-1)/2*cnt[i];
		else ans+=1ll*cnt[k]*cnt[j]*cnt[k];
	}
	cout<<ans<<endl;return 0;
}