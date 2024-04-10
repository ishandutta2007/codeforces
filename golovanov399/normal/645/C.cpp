#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	vector<int> a;
	for (int i = 0; i < n; i++){
		if (s[i] == '0')
			a.push_back(i);
	}

	int ans = n + 1;
	int sz = a.size();
	for (int i = 0; i < sz; i++){
		int l = max(0, k - (sz - 1 - i));
		int r = min(k, i) + 1;
		// cerr << i << ": " << l << " " << r << "\n";
		while (r > l + 1){
			int mid = (l + r) / 2;
			if (a[i] - a[i - mid] <= a[i + k - mid] - a[i])
				l = mid;
			else
				r = mid;
		}
		ans = min(ans, max(a[i] - a[i - l], a[i + k - l] - a[i]));
		if (i >= r && i + k - r < sz){
			ans = min(ans, max(a[i] - a[i - r], a[i + k - r] - a[i]));
		}
	}

	cout << ans << "\n";

	return 0;
}