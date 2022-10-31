#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 1050
int a[N],n,vis[N];
void solve(int s) {
	int i;
	memset(vis,0,sizeof(vis));
	int p=s; vis[s]=1;
	for(p=a[p];!vis[p];p=a[p])vis[p]=1;
	printf("%d ",p);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) solve(i);
}