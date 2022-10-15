#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n, 1e6);
	for (int i = 0; i < n; ++i) cin >> a[i];
	queue<int> use;
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		if (i ? a[i] != a[i - 1] : a[i]){
			if (use.size() + 1 < a[i] - lst) return cout << -1, 0;
			else {
				for (int j = a[i] - 1; j > lst; --j) {
					b[use.front()] = j;
					use.pop();
				}
				b[i] = lst;
				lst = a[i];
			}
		} else {
			use.push(i);
		}	
	}
	for (int el : b) cout << el << ' ';
}