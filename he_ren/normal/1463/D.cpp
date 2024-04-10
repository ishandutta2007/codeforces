#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e5 + 5;

int n;
int b[MAXN];
bool is[MAXN];

int get_res(void)
{
	int cnt = 0, res = 0;
	for(int i=1; i<=2*n; ++i)
	{
		if(!is[i]) ++cnt;
		else if(cnt) --cnt, ++res;
	}
	return res;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=2*n; ++i) is[i] = 0;
	for(int i=1; i<=n; ++i) is[b[i]] = 1;
	
	int lef = get_res();
	reverse(is+1, is+2*n+1);
	int rig = n - get_res();
	if(lef > rig) swap(lef, rig);
	
	printf("%d\n",rig - lef + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}