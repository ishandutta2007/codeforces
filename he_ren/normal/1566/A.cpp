#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	
	int cnt = n / 2 + 1;
	printf("%d\n",s / cnt);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}