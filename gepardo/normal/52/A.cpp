#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	int n; cin >> n;
	vector <int> v(n);
	int c1 = 0, c2 = 0, c3 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] == 1) c1++; else if (v[i] == 2) c2++; else c3++;
	}
	cout << min(c1 + c2, min(c1 + c3, c2 + c3));
}