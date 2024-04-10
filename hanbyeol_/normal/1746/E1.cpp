#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> A(N), B;
	iota(A.begin(), A.end(), 1);
	while (true)
	{
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
		}
		int c = A.size() / 2, d = B.size() / 2;
		if (A.size() == 2 && B.size() == 1)
			c = 2, d = 0;
		if (A.size() % 2 == 1 && B.size() % 2 == 1)
			++d;
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