#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 2013
#define MOD 1000000007
typedef long long LL;
int N;
LL X[MAXN], Y[MAXN];
LL MX, MY;
set<pair<LL, LL> > s1;
unordered_multiset<LL> s;
set<pair<LL, LL> > slopes;

bool go(int p, int q) {
	// pair point 0 with point p
	LL nx = X[q] + X[p]; // norm vectors
	LL ny = Y[q] + Y[p];
	LL g = __gcd(nx, ny);
	nx /= g;
	ny /= g;
	if (nx < 0 || (nx == 0 && ny < 0)) {
		nx = -nx;
		ny = -ny;
	}
	pair<LL, LL> pp = {nx, ny};
	if (slopes.count(pp)) return false;
	slopes.insert(pp);

	s.clear();
	for (int i = 0; i < N; i++) {
		LL h = ny * X[i] - nx * Y[i];
		auto it = s.find(-h);
		if (it != s.end()) {
			s.erase(it);
		}
		else {
			s.insert(h);
		}
	}
	return s.size() <= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		MX += X[i];
		MY += Y[i];
		X[i] *= N;
		Y[i] *= N;
	}

	// Step 1: Normalization
	for (int i = 0; i < N; i++) {
		X[i] -= MX;
		Y[i] -= MY;
	}

	// Step 2: Removal of "useless" points
	for (int i = 0; i < N; i++) {
		pair<LL, LL> np = {-X[i], -Y[i]};
		if (s1.count(np)) {
			s1.erase(np);
		}
		else {
			s1.insert(make_pair(X[i], Y[i]));
		}
	}

	N = 0;
	for (pair<LL, LL> p : s1) {
		X[N] = p.first, Y[N]=p.second;
		N++;
	}

	if (N <= 1) {
		cout << -1 << endl;
		return 0;
	}

	// Step 3: Try pairing 0 with every point p
	int ans = 0;
	for (int p = 0; p < N; p++) {
		if (go(0, p)) {
			++ans;
		}
	}

	cout << ans << endl;
	return 0;
}