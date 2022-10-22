#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2001
#define MAXM 1000001
int T,N,a[MAXN],ans[MAXN][2],cnt[MAXM];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N*2)cin>>a[i];sort(a+1,a+N*2+1);bool win=0;
		FOR(i,N*2-1,1)
		{
			For(j,1,N*2)cnt[a[j]]++;cnt[a[N*2]]--,cnt[a[i]]--;int tot=1,x=a[N*2];ans[1][0]=a[N*2],ans[1][1]=a[i];bool flag=1;
			FOR(j,N*2-1,1)if(cnt[a[j]]){cnt[a[j]]--;if(!cnt[x-a[j]]){flag=0;break;}cnt[x-a[j]]--;ans[++tot][0]=a[j],ans[tot][1]=x-a[j];x=a[j];}
			if(flag){cout<<"YES\n"<<a[N*2]+a[i]<<endl;win=1;For(j,1,N)cout<<ans[j][0]<<' '<<ans[j][1]<<endl;break;}For(j,1,N*2)cnt[a[j]]=0;
		}
		if(!win)cout<<"NO\n";For(i,1,N*2)cnt[a[i]]=0;
	}
	return 0;
}