#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
#define N 100050
typedef long long ll;
int n,a[N],b[N];
priority_queue<pair<int,int> >q;
ll sum[2];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),q.push(make_pair(a[i],1));
	for(i=1;i<=n;i++) scanf("%d",&b[i]),q.push(make_pair(b[i],0));
	for(i=1;i<=n+n;i++) {
		pair<int,int> PP=q.top(); q.pop();
		if((i&1)==PP.second) sum[i&1]+=PP.first;
		else ;
	}
	printf("%lld\n",sum[1]-sum[0]);
}