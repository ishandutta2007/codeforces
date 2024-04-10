#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b,x,y;
	scanf("%d%d%d%d",&a,&b,&x,&y);
	
	if(b==y && a+x == b){ printf("Yes\n"); return;}
	if(b==x && a+y == b){ printf("Yes\n"); return;}
	if(a==y && b+x == a){ printf("Yes\n"); return;}	
	if(a==x && b+y == a){ printf("Yes\n"); return;}	
	printf("No\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}