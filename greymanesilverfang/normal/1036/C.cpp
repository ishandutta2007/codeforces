#include <iostream>
#include <stack>
using namespace std;

long long solve(long long x)
{
	const int SAME = 0, LESS = 1;
	long long f[4][2] = {{1,0},{0,0},{0,0},{0,0}};
	stack<int> X;
	while (x > 0)
	{
		X.push(x % 10);
		x /= 10;
	}
	while (!X.empty())
	{
		if (X.top() > 0)
		{
			f[3][LESS] += f[3][SAME] + f[2][SAME] * (X.top() - 1) + f[2][LESS] * 9;
			f[2][LESS] += f[2][SAME] + f[1][SAME] * (X.top() - 1) + f[1][LESS] * 9;
			f[1][LESS] += f[1][SAME] + f[0][SAME] * (X.top() - 1) + f[0][LESS] * 9;
			f[0][LESS]  = 1;
			f[3][SAME]  = f[2][SAME];
			f[2][SAME]  = f[1][SAME];
			f[1][SAME]  = f[0][SAME];
			f[0][SAME]  = 0;
		}
		else 
		{
			f[3][LESS] += f[2][LESS] * 9;
			f[2][LESS] += f[1][LESS] * 9;
			f[1][LESS] += f[0][LESS] * 9;
			f[0][LESS]  = 1;
		}
		X.pop();
	}
	return f[3][LESS] + f[2][LESS] + f[1][LESS] + f[0][LESS];
}

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		long long L, R; cin >> L >> R;
		cout << solve(R + 1) - solve(L) << endl;
	}
	return 0;
}