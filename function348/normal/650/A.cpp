#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#define FR first
#define SC second
using namespace std;
const int N=200010;
typedef pair<int,int> PII;
typedef long long LL;
int n;
PII a[N];
map<int,int> S;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int p=S[a[i].FR];
		ans-=1LL*p*(p-1)/2;
		p++;
		ans+=1LL*p*(p-1)/2;
		S[a[i].FR]=p;
	}
	S.clear();
	for (int i=1;i<=n;i++)
	{
		int p=S[a[i].SC];
		ans-=1LL*p*(p-1)/2;
		p++;
		ans+=1LL*p*(p-1)/2;
		S[a[i].SC]=p;
	}
	
	int cnt=1;
	sort(a+1,a+1+n);
	a[n+1].FR=a[n].FR+10;
	for (int i=2;i<=n+1;i++)
	if (a[i].FR!=a[i-1].FR||a[i].SC!=a[i-1].SC) ans-=1LL*cnt*(cnt-1)/2,cnt=1;
	else cnt++;
	printf("%I64d\n",ans);
	return 0;
}