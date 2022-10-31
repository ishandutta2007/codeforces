#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
#define MP make_pair
const int N=200010,p=1000000007;
typedef pair<int,int> PII;
int n,cnt,num,ans,t;
int pw[N],v[N],v1[N],v2[N];
int x[N],y[N];
map<int,int> S;
multiset<PII> A[N],B[N];
void dfs(int i,int fa,int ffa)
{
	if (i==ffa) return;
	if (v[i]==num) { t=0;return;}
	v[i]=num;
	if (v1[x[i]]==0) v1[x[i]]=1,cnt++;
	if (v2[y[i]]==0) v2[y[i]]=1,cnt++;
	multiset<PII>::iterator it;
	it=A[x[i]].upper_bound(MP(x[i],i));
	if (it!=A[x[i]].end()) dfs((*it).second,i,fa);
	it--;
	if (it!=A[x[i]].begin()) { it--;dfs((*it).second,i,fa);}

	it=B[y[i]].upper_bound(MP(y[i],i));
	if (it!=B[y[i]].end()) dfs((*it).second,i,fa);
	it--;
	if (it!=B[y[i]].begin()) { it--;dfs((*it).second,i,fa);}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (S.find(x[i])==S.end()) S.insert(MP(x[i],++cnt));
		if (S.find(y[i])==S.end()) S.insert(MP(y[i],++cnt));
		x[i]=S[x[i]];y[i]=S[y[i]];
		A[x[i]].insert(MP(x[i],i));
		B[y[i]].insert(MP(y[i],i));
	}
	pw[0]=1;ans=1;
	for (int i=1;i<=n+1;i++) pw[i]=pw[i-1]*2%p;
	for (int i=1;i<=n;i++)
	if (v[i]==0)
	{
		num++;t=-1;cnt=0;
		dfs(i,0,0);
		ans=1LL*ans*(pw[cnt]+t)%p;
	}
	printf("%d\n",ans);
	return 0;
}