#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,a[MAXN];ll sum[MAXN];bool vis[MAXN];map<ll,bool>in;
void sol(int l,int r){in[sum[r]-sum[l-1]]=1;if(l==r)return;if(a[l]==a[r])return;int pos=upper_bound(a+l,a+r+1,a[l]+a[r]>>1)-a-1;sol(l,pos),sol(pos+1,r);}
int main()
{
	cin>>T;
	while(T--)
	{
		in.clear();cin>>N>>M;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);For(i,1,N)sum[i]=sum[i-1]+a[i];sol(1,N);
		For(i,1,M){int x;cin>>x;cout<<(in[x]?"Yes\n":"No\n");}
	}
	return 0;
}