#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e5 + 5;
using namespace std;

inline int abs(int x){ return x<0? -x: x;}

struct Node
{
	int x,id;
}a[MAXN];
inline bool cmp(Node a,Node b){ return a.x<b.x;}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	
	ll ans=0;
	for(int i=1; i<n; ++i)
	{
		ans += abs(a[i].id-a[i+1].id);
	}
	cout<<ans;
	return 0;
}