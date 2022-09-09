#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int pos = n;
	while(pos >= 1 && a[pos] == 1) --pos;
	for(int i=1; i<=pos; ++i) printf("%d ",i);
	printf("%d ",n+1);
	for(int i=pos+1; i<=n; ++i) printf("%d ",i);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}