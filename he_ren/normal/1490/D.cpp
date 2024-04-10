#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];
int res[MAXN];

void solve(int l,int r,int d)
{
	if(l>r) return;
	int mid = max_element(a+l,a+r+1) - a;
	res[mid] = d;
	solve(l,mid-1,d+1); solve(mid+1,r,d+1);
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	solve(1,n,0);
	
	for(int i=1; i<=n; ++i) printf("%d ",res[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}