#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
int n,ans;
int f[N];
PII a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	sort(a+1,a+1+n);
	ans=n;
	for (int i=1;i<=n;i++)
	{
		int j=lower_bound(a+1,a+i,MP(a[i].FR-a[i].SC,0))-a-1;
		f[i]=f[j]+1;
		ans=min(ans,n-f[i]);
	}
	printf("%d\n",ans);
	return 0;
}