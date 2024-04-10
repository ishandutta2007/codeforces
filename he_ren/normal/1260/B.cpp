#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b) swap(a,b);
	
	if(a-b > b){ printf("NO\n"); return;}
	if((b - (a-b))%3) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}