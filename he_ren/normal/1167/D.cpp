#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int now = 0;
	for(int i=1; i<=n; ++i)
	{
		int res;
		if(s[i] == '(')
		{
			++now;
			res = now&1;
		}
		else
		{
			res = now&1;
			--now;
		}
		putchar(res+'0');
	}
	return 0;
}