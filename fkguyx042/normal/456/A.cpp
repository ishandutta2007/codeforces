#include <cstdio>
#include <algorithm>
using namespace std;
struct node{int w,v;}a[1000005];
int n,m,i,h;
inline bool cmp(node a,node b){return a.w<b.w;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&a[i].w,&a[i].v);
	sort(a+1,a+1+n,cmp);
	for(i=1;i<n;i++)if (a[i+1].v<a[i].v)h=1;
	if (h)printf("Happy Alex");
	else printf("Poor Alex");
	return 0;
}