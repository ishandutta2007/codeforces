#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[222222],b[222222],pre,pos;
long long mx,cur;
bool used[222222];
pair<int,int> c[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=a[i]-i;
	for (int i=1;i<=n;i++) c[i]=make_pair(b[i],i);
	sort(c+1,c+n+1);
	pos=1;
	while(pos<=n)
	{
		pre=pos;
		while(pos<=n && c[pos].first==c[pre].first) pos++;
		cur=0;
		for (int i=pre;i<pos;i++) cur+=a[c[i].second];
		mx=max(mx,cur);
	}
	printf("%lld\n",mx);
	return Accepted;
}