#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	
	int tmp = max(y + z - x + 1, 0);
	if(tmp>z*2) printf("0\n");
	else if(tmp%2 == 0) printf("%d\n",(z*2 - tmp)/2 + 1);
	else printf("%d\n",(z*2 - tmp)/2 + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}