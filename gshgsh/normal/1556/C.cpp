#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,a[MAXN];ll b[MAXN],ans;
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];N=(N>>1)<<1;
	for(int i=1;i<=N;i+=2)
	{
		For(i,1,N)b[i]=a[i];ans+=min(b[i],b[i+1]);if(i+3<=N)ans+=max(min(b[i]-b[i+1],b[i+3]-b[i+2])+1,0ll);
		for(int j=i+5;j<=N;j+=2){ll x=min(b[j-3],b[j-2]);b[j-3]-=x,b[j-2]-=x;if(b[j-2])b[i+1]+=b[j-2];if(b[j-3])b[j-1]+=b[j-3];ans+=max(min(b[i]-b[i+1],b[j]-b[j-1])+1,0ll);}
	}
	cout<<ans<<'\n';return 0;
}