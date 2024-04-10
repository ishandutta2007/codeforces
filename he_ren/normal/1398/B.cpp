#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	vector<int> a;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i]==s[j]) ++j;
		if(s[i] == '1') a.push_back(j-i);
	}
	
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	
	int ans = 0;
	for(int i=0; i<(int)a.size(); i+=2)
		ans += a[i];
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}