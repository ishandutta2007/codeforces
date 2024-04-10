#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int del = 0, cnt1 = 0, cnt2 = 0;//cnt1 = '(', cnt2 = '['
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(') ++cnt1;
		if(s[i] == '[') ++cnt2;
		if(s[i] == ')')
		{
			if(cnt1) --cnt1;
			else ++del;
		}
		if(s[i] == ']')
		{
			if(cnt2) --cnt2;
			else ++del;
		}
	}
	
	printf("%d\n",(n - del - cnt1 - cnt2)/2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}