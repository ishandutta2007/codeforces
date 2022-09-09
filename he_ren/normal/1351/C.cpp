#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
const int MAXN = 1e5 + 5;

char s[MAXN];
set<piiii> t;

void solve(void)
{
	t.clear();
	
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	pii now(0,0);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		pii tmp = now;
		int &x = tmp.first;
		int &y = tmp.second;
		
		if(s[i]=='N') --x;
		if(s[i]=='S') ++x;
		if(s[i]=='E') ++y;
		if(s[i]=='W') --y;
		
		if(t.find(make_pair(tmp,now)) != t.end())
			++ans;
		else
		{
			ans += 5;
			t.insert(make_pair(tmp,now));
			t.insert(make_pair(now,tmp));
		}
		now=tmp;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}