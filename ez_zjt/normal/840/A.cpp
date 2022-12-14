#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
using namespace std;

int n;
int a[MAXN],b[MAXN];
pair<int,int> v[MAXN];
int ans[MAXN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		v[i].first=b[i];
		v[i].second=i;
	}
	sort(a+1,a+n+1);
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)
		ans[v[i].second]=a[n-i+1];
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}