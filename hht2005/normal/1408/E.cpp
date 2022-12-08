#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define mp make_pair
typedef pair<int,int> pii;
priority_queue<pii>q;
vector<int>s[maxn];
int a[maxn],b[maxn],fa[maxn];
int cmp(int x,int y) {
	return b[x]<b[y];
}
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main() {
	int n,m,k,v,cnt=0;
	long long ans=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<n+m;i++)fa[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d",&k);
		for(int j=1;j<=k;j++) {
			scanf("%d",&v);
			ans+=a[i]+b[v];
			s[i].push_back(v);
		}
		sort(s[i].begin(),s[i].end(),cmp);
		q.push(mp(a[i]+b[*s[i].rbegin()],i));
	}
	while(!q.empty()&&cnt<n+m-1) {
		pii t=q.top();
		q.pop();
		if(get(t.second+n)!=get(*s[t.second].rbegin())) {
			ans-=t.first;
			cnt++;
			fa[get(t.second+n)]=get(*s[t.second].rbegin());
		}
		if(s[t.second].size()>1) {
			s[t.second].pop_back();
			q.push(mp(a[t.second]+b[*s[t.second].rbegin()],t.second));
		}
	}
	printf("%lld\n",ans);
	return 0;
}