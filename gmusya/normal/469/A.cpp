#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> tf(n);
	int p;
	cin >> p;
	vector <int> a(p);
	for (int i = 0; i < p; i++)
		cin >> a[i];
	int q;
	cin >> q;
	vector <int> b(q);
	for (int i = 0; i < q; i++)
		cin >> b[i];
	for (int i = 0; i < p; i++)
		tf[a[i] - 1] = true;
	for (int i = 0; i < q; i++)
		tf[b[i] - 1] = true;
	bool ans = true;
	for (int i = 0; i < n; i++)
		if (!tf[i])
			ans = false;
	if (ans)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";
	return 0;
}