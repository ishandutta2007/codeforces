#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int n = abs(b - a) * 2;
	if(a > n || b > n || c > n) printf("-1\n");
	else printf("%d\n",(c + n / 2 - 1) % n + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}