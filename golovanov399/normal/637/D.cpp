#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void solve(int n, int m, int s, int d, vector<int> a){
	sort(all(a));

	// cerr << n << " " << m << " " << s << " " << d << "\n";
	// for (auto x : a)
	// 	cerr << x << " ";
	// cerr << "\n";

	if (a[0] <= s){
		puts("IMPOSSIBLE");
		return;
	}

	vector<pair<int, int>> ev;
	for (int i = 0; i < n; i++){
		ev.pb(a[i] - s, -1);
		ev.pb(a[i], 1);
	}
	sort(all(ev));
	vector<pair<int, int>> bad;
	int pr = -1;
	int bal = 0;
	for (auto p : ev){
		if (bal == 0)
			pr = p.first;
		bal += p.second;
		if (bal == 0)
			bad.pb(pr, p.first);
	}
	vector<pair<int, int>> lol;
	for (auto p : bad){
		if (lol.empty() || lol.back().second + 1 < p.first)
			lol.push_back(p);
		else
			lol.back().second = p.second;
	}
	lol.swap(bad);
	for (auto p : bad){
		if (p.second - p.first + 2 > s + d){
			puts("IMPOSSIBLE");
			return;
		}
	}

	int cur = 0;
	cout.sync_with_stdio(0);
	for (auto p : bad){
		int nw = p.first - 1;
		nw += s;
		cout << "RUN " << nw - cur;
		// assert(nw - cur >= s);
		cout << "\nJUMP " << p.second - p.first + 2 - s << "\n";
		// assert(p.second - p.first + 2 - s <= d);
		cur = p.second + 1;
	}
	if (cur < m){
		cout << "RUN " << m - cur << "\n";	
	}
}

int main(){

	while (true){

		// int m = rand() % 91 + 10;
		// int n = rand() % (m - 2) + 1;
		// vector<int> a(m - 1);
		// for (int i = 0; i < m - 1; i++)
		// 	a[i] = i + 1;
		// random_shuffle(all(a));
		// a.resize(n);
		// int s = rand() % m + 1, d = rand() % m + 1;

		int n = nxt(), m = nxt();
		long long s = nxt(), d = nxt();
		vector<itn> a(n);
		for (int i = 0; i < n; i++)
			a[i] = nxt();

		solve(n, m, s, d, a);

		break;
	}

	return 0;
}