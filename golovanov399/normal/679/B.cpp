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

inline unsigned long long f(unsigned long long n){
	return 3ull * n * n + 3ll * n + 1;
}

pair<int, unsigned long long> solve(unsigned long long n){
	vector<unsigned long long> s(1, 0);
	vector<unsigned long long> a;
	while (s.back() <= n){
		unsigned long long x = (a.empty() ? 0 : a.back());
		if (x == 0)
			x = 1;
		while (f(x) <= s.back())
			x++;
		unsigned long long y = s.back();
		s.push_back(y + x * x * x);
		a.push_back(x);
	}
	s.pop_back();
	a.pop_back();
	unsigned long long m = s.back();
	unsigned long long cur = m;
	unsigned long long available = n - m + 1;
	for (int i = (int)a.size() - 1; i >= 0; i--){
		// for (auto x : a)
		// 	cerr << x << " ";
		// cerr << "\n";
		// cerr << available << "\n";
		cur -= a[i] * a[i] * a[i];
		while (m - + f(a[i]) <= n && f(a[i]) < available){
			m += f(a[i]);
			available -= f(a[i]);
			a[i]++;
		}
		available = min(available, f(a[i]) - cur);
		// cerr << f(a[i]) - cur << "\n";
	}

	return make_pair((int)a.size(), m);	
}

int ololo(unsigned long long n){
	unsigned long long x = pow(n, 1/3) + 100;
	int res = 0;
	while (n > 0){
		if (x * x * x <= n){
			res++;
			n -= x * x * x;
		} else {
			x--;
		}
	}
	return res;
}

pair<int, unsigned long long> stupid(unsigned long long n){
	pair<int, unsigned long long> ans = {0, 0};
	for (int i = 1; i <= n; i++){
		pair<int, unsigned long long> tmp = {ololo(i), i};
		ans = max(ans, tmp);
	}
	return ans;
}

int main(){

	unsigned long long n;
	cin >> n;
	auto p = solve(n);
	cout << p.first << " " << p.second << "\n";

	// for (int i = 1; i < 10000; i++){
	// 	auto p = solve(i), q = stupid(i);
	// 	if (p != q){
	// 		cerr << i << "\n";
	// 		cerr << p.first << " " << p.second << "\n";
	// 		cerr << q.first << " " << q.second << "\n";
	// 		return 0;
	// 	}
	// }

	return 0;
}