#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		a[i]--;
	bool tf = false;
	for (int i = 0; i < n; i++)
		if (a[a[a[i]]] == i)
			tf = true;
	if (tf)	
		cout << "YES";
	else
		cout << "NO";
	return 0;
}