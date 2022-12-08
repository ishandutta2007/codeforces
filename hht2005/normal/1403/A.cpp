#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
const int maxn=2e5+10;
int a[10],b[maxn],las[maxn];
pair<int,int>p[maxn*6];
int main() {
	int n,cnt=0,ans=1e9;
	for(int i=1;i<=6;i++)
		scanf("%d",a+i);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",b+i);
		for(int j=1;j<=6;j++)//asdfrgtfh
			p[++cnt]=make_pair(b[i]-a[j],i);
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<=n;i++)s.insert(las[i]=-1e9);
	for(int i=1;i<=cnt;i++) {
		s.erase(s.find(las[p[i].second]));
		s.insert(las[p[i].second]=p[i].first);
		ans=min(ans,p[i].first-*s.begin());
	}
	printf("%d\n",ans);
	return 0;
}