
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 4e6+5;

int ans[ms];
int pre[ms];

main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int n = (a+b);
		int qntA = n/2;
		vector<int> possiblesK = {-1};
		if(a > b) swap(a, b);
		for (int i = 0; i <= a; i++) {
			// cout << a << ' ' << i << endl;
			possiblesK.push_back(qntA - a + i*2);
			if (n % 2) possiblesK.push_back(qntA - a + i*2 + 1);
		}
		sort(possiblesK.begin(), possiblesK.end());
		cout << possiblesK.size() - 1 << '\n';
		for(int i = 1; i < possiblesK.size(); i++) {
			cout << possiblesK[i] << ' ';
		}
		cout << '\n';
	}
}