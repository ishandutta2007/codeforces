#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,K,a[MAXN],cnt[26],ans[MAXN];
bool check(int x)
{
	if(x==N){For(i,0,25)if(cnt[i]%K)return 0;For(i,1,N)ans[i]=a[i];return 1;}
	For(i,a[x+1]+1,25)
	{
		cnt[i]++;int sum=0;For(j,0,25)sum+=(K-cnt[j]%K)%K;
		if(sum<=N-x-1&&(N-x-1-sum)%K==0){For(j,1,x)ans[j]=a[j];ans[x+1]=i;For(j,x+2,N-sum)ans[j]=0;For(j,0,25)For(k,1,(K-cnt[j]%K)%K)sum--,ans[N-sum]=j;return 1;}cnt[i]--;
	}
	return 0;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,0,25)cnt[i]=0;For(i,1,N){char c;cin>>c;cnt[a[i]=c-'a']++;}if(N%K){cout<<-1<<endl;continue;}
		FOR(i,N,0)if(check(i)){For(j,1,N)cout<<char(ans[j]+'a');cout<<endl;break;}else cnt[a[i]]--;
	}
	return 0;
}