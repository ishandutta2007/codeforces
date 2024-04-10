#include <stack>
#include <cstdio>
using namespace std;
int a[(int)2e5];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	stack<int> S;
	int floor = 1;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == floor)
			while (++floor)
				if (!S.empty() && S.top() == floor)
					S.pop();
				else break;
		else if (S.empty() || S.top() > a[i])
			S.push(a[i]);
		else {
			printf("-1");
			return 0;
		}
	}
	for (int i = 0; i < k; ++i)
		printf("%d ", a[i]);
	for (; !S.empty(); floor = ++S.top(), S.pop())
		for (int i = S.top(); i > floor;)
			printf("%d ", --i);
	for (int i = n + 1; i > floor;)
		printf("%d ", --i);
	return 0;
}