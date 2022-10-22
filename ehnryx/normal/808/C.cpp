#include <bits/stdc++.h>
using namespace std;

struct Cup {
	int i;
	int cap;
};

bool cmp(Cup a, Cup b) {
	return a.cap > b.cap;
}
bool order(Cup a, Cup b) {
	return a.i < b.i;
}

int main() {
	vector<Cup> arr;
	vector<Cup> ans;
	int n, w, temp;
	cin >> n >> w;
	arr.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].cap;
		arr[i].i = i;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		ans[i].i = arr[i].i;
		ans[i].cap = (1+arr[i].cap)/2;
		w -= ans[i].cap;
	}
	for (int i = 0; i < n && w > 0; i++) {
		temp = min(w, arr[i].cap - ans[i].cap);
		w -= temp;
		ans[i].cap += temp;
	}
	if (w < 0)
		cout << -1 << endl;
	else {
		sort(ans.begin(), ans.end(), order);
		for (int i = 0; i < n; i++)
			cout << ans[i].cap << " "; 
		cout << endl;
	}

	return 0;
}