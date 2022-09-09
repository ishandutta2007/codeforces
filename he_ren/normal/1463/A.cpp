#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a[5];
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	sort(a+1,a+3+1);
	
	int num = (a[1] + a[2] + a[3]) / 9;
	if((a[1] + a[2] + a[3]) - num * 9 != 0) printf("NO\n");
	else
	{
		if(a[1] < num) printf("NO\n");
		else printf("YES\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}