#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		string cur = string(200, 'a');
		cout << cur << '\n';
		for (int i = 0; i < n; ++i) {
			string New = cur;
			for (int j = a[i]; j < 200; ++j) {
				if (cur[j] == 'b') New[j] = 'c';
				else New[j] = 'b';
			}
			cout << New << '\n';
			cur = New;
		}
//		cerr << "/*--------------------------------------------------------------------------*/\n";
	}
}