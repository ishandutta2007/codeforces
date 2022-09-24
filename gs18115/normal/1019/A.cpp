#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXN=3e3+10;
vector<LL>V[MAXN];
vector<LL>S;
LL work[MAXN],cnt[MAXN];
LL i,j;
LL N,M,ct;
LL P,C;
LL ans,mini;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(i=0;i<N;i++)
	{
		cin>>P>>C;
		P--;
		cnt[P]++;
		if(P>0)
			V[P].push_back(C);
	}
	for(i=1;i<M;i++)
		ct=max(ct,cnt[i]);
	if(ct<cnt[0])
		return cout<<0<<endl,0;
	for(i=1;i<M;i++)
		sort(V[i].begin(),V[i].end());
	mini=INF;
	for(i=1+cnt[0];i<=N;i++)
	{
		fill(work,work+M,0);
		ans=ct=0;
		for(j=1;j<M;j++)
		{
			for(LL&k=work[j];k<=cnt[j]-i;k++)
				ans+=V[j][k];
			ct+=work[j];
		}
		if(ct>i)
			continue;
		S.clear();
		for(j=1;j<M;j++)
			for(LL&k=work[j];k<cnt[j];k++)
				S.push_back(V[j][k]);
		sort(S.begin(),S.end());
		for(j=0;j<i-ct-cnt[0];j++)
			ans+=S[j];
		mini=min(mini,ans);
	}
	cout<<mini<<endl;
	return 0;
}