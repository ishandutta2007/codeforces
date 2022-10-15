#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> pl(n + 1), ct(n<<1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pl[x] = i;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (pl[x] < i) {
			++ct[pl[x] + n - i];
		} else ++ct[pl[x] - i];
	}
	cout << (*max_element(ct.begin(), ct.end())) << '\n';
}