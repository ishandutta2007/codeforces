#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a[3];
	for(int &x: a)
		scanf("%d",&x);
	
	sort(a,a+3);
	
	bool ok = 0;
	if(a[2] == a[0] + a[1]) ok = 1;
	if(a[2] % 2 == 0 && a[0] == a[1]) ok = 1;
	if(a[0] % 2 == 0 && a[1] == a[2]) ok = 1;
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}