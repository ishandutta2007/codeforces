#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],c[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}For(i,1,N){char c;cin>>c;b[i]=c-'0';}For(i,1,N)c[i]=a[i]^b[i];
		int cnt1=0,cnt2=0;For(i,1,N)cnt1+=a[i];For(i,1,N)cnt2+=b[i];if(cnt1!=cnt2&&cnt1+cnt2!=N+1){cout<<"-1\n";continue;}
		bool flag=0;int cnt=0;For(i,1,N)if(a[i])flag=1;For(i,1,N)cnt+=c[i];if(!flag&&cnt){cout<<"-1\n";continue;}
		if(!cnt){cout<<"0\n";continue;}bool flag1=0;For(i,1,N)flag1|=b[i];if(!flag1){cout<<"-1\n";continue;}
		int ans=N+1;if(cnt%2==0&&cnt1==cnt2)ans=min(ans,cnt);if((N-cnt&1)&&cnt1+cnt2==N+1)ans=min(ans,N-cnt);if(ans==N+1)cout<<"-1\n";else cout<<ans<<'\n';
	}
}