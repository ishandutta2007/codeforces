#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}
		int x=0;For(i,1,N-(N>>1))if(!a[i]){x=i;break;}if(x){cout<<x<<' '<<N<<' '<<x+1<<' '<<N<<'\n';continue;}
		For(i,(N>>1)+1,N)if(!a[i]){x=i;break;}if(x){cout<<1<<' '<<x<<' '<<1<<' '<<x-1<<'\n';continue;}
		cout<<1<<' '<<N-1<<' '<<2<<' '<<N<<'\n';
	}
	return 0;
}