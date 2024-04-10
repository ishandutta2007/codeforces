#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a[10];

void solve(void)
{
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
	
	vector<int> b(a+1,a+4+1);
	sort(b.begin(),b.end());
	
	int x = max(a[1], a[2]), y = max(a[3], a[4]);
	if(x < y) swap(x,y);
	
	if(x == b[3] && y == b[2]) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}