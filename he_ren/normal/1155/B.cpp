#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int x = (n-11)/2;
	
	vector<int> vec;
	
	for(int i=1; i<=n; ++i)
		if(s[i]=='8')
			vec.push_back(i);
	
	if((int)vec.size() <= x){ printf("NO"); return;}
	
	if(vec[x]-1 - x <= x) printf("YES");
	else printf("NO");
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}