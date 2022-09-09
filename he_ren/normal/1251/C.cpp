#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 3e5 + 5;

char s[MAXN];
queue<char> q[2];

void solve(void)
{	
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i)
		q[(s[i]-'0')&1].push(s[i]);
	
	while(!q[0].empty() && !q[1].empty())
	{
		if(q[0].front()<q[1].front()) putchar(q[0].front()), q[0].pop();
		else putchar(q[1].front()), q[1].pop();
	}
	for(int i=0; i<=1; ++i)
		while(!q[i].empty()) putchar(q[i].front()), q[i].pop();
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}