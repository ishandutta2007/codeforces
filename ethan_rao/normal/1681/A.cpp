#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, m, i, j;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;
		cin >> m;
		vector<int> b(m);
		for (int &x : b)
			cin >> x;
		int x = *max_element(all(a)), y = *max_element(all(b));
		if (x == y)
			cout << "Alice\nBob\n";
		else if (x < y)
			cout << "Bob\nBob\n";
		else
			cout << "Alice\nAlice\n";
	}
}