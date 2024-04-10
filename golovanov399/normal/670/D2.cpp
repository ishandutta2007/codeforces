#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define li long long

using namespace std;

inline int nxt(){
	int n;
	scanf("%d", &n);
	return n;
}

int main(){

	int n = nxt(), k = nxt();
	vector<long long> a(n);
	vector<long long> b(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	for (int i = 0; i < n; i++)
		b[i] = nxt();

	long long l = 0, r = 2222222222ll;
	while (r > l + 1){
		long long mid = (l + r) / 2;
		long long need = 0;
		bool bad = false;
		for (int i = 0; i < n; i++){
			need += max(0ll, a[i] * mid - b[i]);
			if (need > k)
				bad = true;
		}
		if (need <= k && !bad)
			l = mid;
		else
			r = mid;
	}

	cout << l << "\n";

	return 0;
}