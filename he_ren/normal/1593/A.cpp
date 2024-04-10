#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int get(int a,int b,int c)
{
	return max(0, max(b + 1 - a, c + 1 - a));
}

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d %d %d\n",get(a,b,c),get(b,a,c),get(c,b,a));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}