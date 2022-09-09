#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int p[MAXN];
char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	scanf("%s",s+1);
	
	static int id[MAXN];
	for(int i=1; i<=n; ++i) id[i] = i;
	sort(id+1,id+n+1, [](int x,int y){
		return s[x] != s[y]? s[x] < s[y]: p[x] < p[y];
	});
	
	static int q[MAXN];
	for(int i=1; i<=n; ++i) q[id[i]] = i;
	
	for(int i=1; i<=n; ++i) printf("%d ",q[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}