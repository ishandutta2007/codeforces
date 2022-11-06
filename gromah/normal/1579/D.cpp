#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int Case, n, ans, Ans[N][2];

struct Node
{
	int a, id;
	Node() {}
	Node(int a, int id) : a(a), id(id) {}
	bool operator < (const Node &rhs) const
	{
		return make_pair(a, id) < make_pair(rhs.a, rhs.id);
	}
};

priority_queue<Node> Q;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1, a; i <= n; i ++)
		{
			scanf("%d", &a);
			Q.push(Node(a, i));
		}
		ans = 0;
		while (1)
		{
			Node x = Q.top();
			Q.pop();
			Node y = Q.top();
			Q.pop();
			if (y.a == 0)
				break;
			x.a --, y.a --;
			ans ++;
			Ans[ans][0] = x.id, Ans[ans][1] = y.id;
			Q.push(x);
			Q.push(y);
		}
		printf("%d\n", ans);
		for (int i = 1; i <= ans; i ++)
			printf("%d %d\n", Ans[i][0], Ans[i][1]);
	}
	return 0;
}