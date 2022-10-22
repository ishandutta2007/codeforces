#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int T,N,a[MAXN],b[MAXN],cnt[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';cnt[i]=cnt[i-1]+a[i];}For(i,1,N){char c;cin>>c;b[i]=c-'0';}
		bool flag=1;int now=0;FOR(i,N,1)if((a[i]^now)!=b[i]){if(cnt[i]*2!=i){flag=0;break;}now^=1;}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}