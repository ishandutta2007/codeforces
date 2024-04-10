#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	vector<int> pos;
	for(int i=1; i<=n; ++i)
		if(s[i] == '*') pos.push_back(i);
	
	vector<int> f(pos.size(), inf);
	f[0] = 1;
	for(int i=1; i<(int)pos.size(); ++i)
		for(int j=i-1; j>=0 && pos[i] - pos[j] <= d; --j)
			f[i] = min(f[i], f[j] + 1);
	printf("%d\n",f.back());
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}