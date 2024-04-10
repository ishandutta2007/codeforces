#include <bits/stdc++.h>
using namespace std;

int D[101][101];
pair<int, int> soln[101][101];
int solve(int a, int b)
{
	if (D[a][b] != 0)
		return D[a][b];
	if (a + b <= 2)
		return 0;
	int ans = 10101;
	for (int c = max(0, a / 2 - 1); c <= min(a / 2 + 1, a); ++c)
		for (int d = max(0, b / 2 - 1); d <= min(b / 2 + 1, b); ++d)
		{
			if (make_tuple(a + d, c + d, a - c) >= make_tuple(a + b, a, b))
				continue;
			if (make_tuple(a + b - d, a + b - (c + d), c) >= make_tuple(a + b, a, b))
				continue;
			int r = 1 + max(solve(c + d, a - c), solve((a + b) - (c + d), c));
			if (ans > r)
			{
				ans = r;
				soln[a][b] = make_pair(c, d);
			}
		}
	return D[a][b] = ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N), B;
	iota(A.begin(), A.end(), 1);
	int q = 0;
	while (true)
	{
		// cout << A.size() << " " << B.size() << endl;
		if (A.size() + B.size() <= 2)
		{
			for (int x : A)
			{
				cout << "! " << x << endl;
				string s;
				cin >> s;
				if (s == ":)")
					return 0;
			}
			for (int x : B)
			{
				cout << "! " << x << endl;
				string s;
				cin >> s;
				if (s == ":)")
					return 0;
			}
			assert(false);
		}
		assert(++q != 54);
		int c = A.size() / 2, d = B.size() / 2;
		if (A.size() % 2 == 1 && B.size() % 2 == 1)
			++d;
		if (A.size() <= 50 && B.size() <= 50)
		{
			solve(A.size(), B.size());
			c = soln[A.size()][B.size()].first;
			d = soln[A.size()][B.size()].second;
		}
		vector<int> V;
		for (int i = 0; i < c; i++)
			V.push_back(A[i]);
		for (int i = 0; i < d; i++)
			V.push_back(B[i]);
		cout << "? " << V.size();
		for (int x : V)
			cout << " " << x;
		cout << endl;
		string s;
		cin >> s;
		vector<int> nA, nB;
		if (s == "NO")
		{
			for (int i = c; i < (int)A.size(); i++)
				nA.push_back(A[i]);
			for (int i = d; i < (int)B.size(); i++)
				nA.push_back(B[i]);
			for (int i = 0; i < c; i++)
				nB.push_back(A[i]);
		}
		else
		{
			nA = V;
			for (int i = c; i < (int)A.size(); i++)
				nB.push_back(A[i]);
		}
		A = nA, B = nB;
	}
}