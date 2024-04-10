#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
const int g_n = 3;
int g;
bool lie = false;
int rem = 82;
#endif

bool ask(vector<int> v) {
#ifdef TEST
	cerr << "trying ";
	for (int x : v) {
		cerr << x << " ";
	}
	cerr << "\n";
	assert(rem--);
	if (lie) {
		lie = false;
	} else {
		lie = rand() % 2;
	}
	cerr << "answer " << ((find(all(v), g) != v.end()) ^ lie) << "\n";
	return (find(all(v), g) != v.end()) ^ lie;
#else
	cout << "? " << v.size();
	for (int x : v) {
		cout << " " << x;
	}
	cout << endl;
	string s;
	cin >> s;
	return s[0] == 'Y';
#endif
}

vector<int> merge(vector<int> a, vector<int> b) {
	a.insert(a.end(), all(b));
	return a;
}

bool guess(int x) {
#ifdef TEST
	cerr << "guessing " << x << "\n";
	return x == g;
#else
	cout << "! " << x << endl;
	string s;
	cin >> s;
	return s == ":)";
#endif
}

void solve() {
#ifdef TEST
	int n = g_n;
	g = rand() % g_n + 1;
	rem = 82;
#else
	int n = nxt();
#endif
	vector<int> a(n);
	iota(all(a), 1);
	while ((int)a.size() > 3) {
		// cerr << a.size() << " ";
		// for (auto x : a) {
		// 	cerr << x << " ";
		// }
		// cerr << "--\n";
		vector<int> parts[4];
		for (int i = 0; i < (int)a.size(); ++i) {
			parts[i * 4 / (int)a.size()].push_back(a[i]);
		}
		bool b1 = ask(merge(parts[0], parts[1]));
		bool b2 = ask(merge(parts[0], parts[2]));
		vector<int> forb1, forb2;
		forb1 = b1 ? merge(parts[2], parts[3]) : merge(parts[0], parts[1]);
		forb2 = b2 ? merge(parts[1], parts[3]) : merge(parts[0], parts[2]);
		// assert(is_sorted(all(forb1)));
		// assert(is_sorted(all(forb2)));
		vector<int> rem;
		for (int x : a) {
			if (!binary_search(all(forb1), x) || !binary_search(all(forb2), x)) {
				rem.push_back(x);
			}
		}
		a.swap(rem);
	}
	// for (auto x : a) {
	// 	cerr << x << " ";
	// }
	// cerr << "-3-\n";
	if ((int)a.size() == 3) {
		if (ask({a[0]}) || ask({a[0]})) {
			if (guess(a[0])) {
				return;
			}
			assert(guess(ask({a[1]}) ? a[1] : a[2]));
			return;
		} else {
			a.erase(a.begin());
		}
	}
	assert((int)a.size() <= 2);
	if (!guess(a[0])) {
		assert(guess(a[1]));
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}