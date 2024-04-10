#include <cstdio>
#include <stack>
const int MAX = 3e5;
char s[MAX];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%s", &s);
		std::stack<int> st;
		for (int i = 0; s[i]; ++i)
		{
			st.push(s[i]);
			if (st.size() >= 2 && st.top() == 'B')
			{
				st.pop();
				st.pop();
			}
		}
		printf("%d\n", st.size());
	}
}