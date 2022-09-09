#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	int ans = 0;
	
	vector<int> len;
	int lenfir = 0, lenlst = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[j] == s[i]) ++j;
		if(s[i] == 'W'){ ans += (j-i) * 2 - 1; continue;}
		
		if(i == 1) lenfir = j-i;
		else if(j>n) lenlst = j-i;
		else len.push_back(j-i);
	}
	
	sort(len.begin(),len.end());
	
	for(int i=0; i<(int)len.size() && d; ++i)
	{
		int use = min(len[i], d);
		len[i] -= use;
		d -= use;
		
		ans += use * 2;
		if(!len[i]) ++ans;
	}
	ans += min(d, lenlst) * 2;
	d -= min(d, lenlst);
	
	if(lenfir == n) ans += min(d, lenfir) * 2 - 1;
	else ans += min(d, lenfir) * 2;
	
	printf("%d\n",max(ans,0));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}