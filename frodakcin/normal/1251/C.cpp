#include <cstdio>
#include <algorithm>
#include <queue>

const int MN = 3e5+10;

int T, N;
char s[MN];
std::queue<int> q[2];

void solve()
{
	scanf(" %s", s);
	for(N=0;s[N];++N)
		q[s[N]&1].push(s[N]);
	for(;!q[0].empty()||!q[1].empty();)
		if(q[0].empty() || !q[1].empty() && q[1].front() < q[0].front())
			printf("%c", q[1].front()), q[1].pop();
		else
			printf("%c", q[0].front()), q[0].pop();
	printf("\n");
}

int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}