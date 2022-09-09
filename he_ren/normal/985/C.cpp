#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXM = 1e5 + 5;

int a[MAXM];

int main(void)
{
	int n,d,l;
	scanf("%d%d%d",&n,&d,&l);
	int m=n*d;
	for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+m+1);
	int r;
	for(r=m; a[r]-a[1]>l; --r);
	if(r<n){ printf("0"); return 0;}
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
		ans += a[min((i-1)*d+1, r-n+i)];
	cout<<ans;
	return 0;
}