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

	int n = nxt(), a = nxt(), b = nxt(), T = nxt();

	int ans = 0;
	string s;
	cin >> s;
	vector<long long> suf(n + 1);
	suf[n] = 0;
	for (int i = n - 1; i >= 0; i--){
		suf[i] = suf[i + 1] + a + 1 + (s[i] == 'w' ? b : 0);
	}
	reverse(all(suf));
	if (suf[n] - a <= T){
		cout << n << "\n";
		return 0;
	}

	long long cur = (s[0] == 'w' ? b : 0) + 1;
	for (int i = 0; i < n && cur <= T; i++){
		long long tmp = 1ll * T - cur - 1ll * i * a;
		int l = 0, r = n;
		while (r > l + 1){
			int mid = (l + r) / 2;
			if (suf[mid] > tmp)
				r = mid;
			else
				l = mid;
		}
		ans = max(ans, i + 1 + l);
		if (i < n - 1)
			cur += a + (s[i + 1] == 'w' ? b : 0) + 1;
	}

	reverse(s.begin() + 1, s.end());
	suf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + a + 1 + (s[i] == 'w' ? b : 0);
	reverse(all(suf));

	cur = (s[0] == 'w' ? b : 0) + 1;
	for (int i = 0; i < n && cur <= T; i++){
		long long tmp = 1ll * T - cur - 1ll * i * a;
		int l = 0, r = n;
		while (r > l + 1){
			int mid = (l + r) / 2;
			if (suf[mid] > tmp)
				r = mid;
			else
				l = mid;
		}
		ans = max(ans, i + 1 + l);
		if (i < n - 1)
			cur += a + (s[i + 1] == 'w' ? b : 0) + 1;
	}

	cout << ans << "\n";

	return 0;
}