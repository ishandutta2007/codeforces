#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

const double pi = 3.14159265358979323846;

void add_edge(vector<vector<int>> &gr, int a, int b)
{
	gr[b].push_back(a);
	gr[a].push_back(b);
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	vector<vector<int>> gr(n);

	cout << (n + k - 2) / k + (n + k - 3) / k << endl;

	for (int i = 0; i < k; i++)
		cout << "1 " << i + 2 << endl;

	for (int i = k + 1; i < gr.size(); i++)
		cout << i - k + 1 << ' ' << i + 1 << endl;

	return 0;
}