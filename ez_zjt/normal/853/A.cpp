#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define MAXN 300010
#define LL long long
using namespace std;

int n,k;
pair<LL,int> c[MAXN];
int ans[MAXN];
set<int> S;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i].first);
		c[i].second=i;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) S.insert(i+k);
	LL res=0;
	for(int i=n;i>=1;i--){
		int x=c[i].second;
		set<int>::iterator it=S.lower_bound(x);
		ans[x]=*it;
		res+=c[i].first*(ans[x]-x);
		S.erase(it);
	}
	printf("%lld\n",res);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}