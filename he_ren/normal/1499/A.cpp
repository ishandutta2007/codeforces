#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int get_res(int x,int y)
{
	if(x>y) swap(x,y);
	return x + (y - x) / 2;
}

void solve(void)
{
	int n,x,y,w,b;
	scanf("%d%d%d%d%d",&n,&x,&y,&w,&b);
	
	if(get_res(x,y) >= w && get_res(n-x,n-y) >= b)
		printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}