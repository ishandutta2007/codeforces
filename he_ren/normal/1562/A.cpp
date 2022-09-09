#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int l,r;
	scanf("%d%d",&l,&r);
	
	l = max(l, (r + 1) / 2);
	printf("%d\n",min(r - l, l - 1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}