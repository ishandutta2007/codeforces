#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x;
	scanf("%d",&x);
	if(x == 1){ printf("1 1\n"); return;}
	
	int y = 0;
	while((ll)y * y < x) ++y;
	--y;
	
	x -= y * y;
	if(x <= y) printf("%d %d\n",x,y+1);
	else printf("%d %d\n",y+1,y+1 - (x-y) + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}