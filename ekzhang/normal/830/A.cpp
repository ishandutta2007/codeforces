#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

// #define int long long
#define MAXN 1013
#define MAXK 2013
int N, K, P;
int A[MAXN];
int B[MAXK];
// {pos, {type, index}}
vector<pair<int, pair<int, int> > > v;
priority_queue<int, vector<int>, greater<int> > pq;
int last[MAXN];

bool solve(int t) {
	v.clear();
	while (pq.size()) pq.pop();
	for (int i = 0; i < N; i++) {
		int d = abs(P - A[i]);
		if (d > t) return false;
		int t2 = t - d;
		int lo, hi;
		if (P > A[i]) {
			lo = A[i] - t2 / 2;
			hi = P + t2 / 2;
		}
		else {
			lo = P - t2 / 2;
			hi = A[i] + t2 / 2;
		}
		last[i] = hi;
		v.push_back({lo, {0, i}});
	}
	for (int i = 0; i < K; i++) {
		v.push_back({B[i], {1, i}});
	}

	sort(v.begin(), v.end());
	for (auto& p : v) {
		int pos = p.first;
		int m = p.second.first, idx = p.second.second;
		if (m == 0) {
			// person
			pq.push(last[idx]);
		}
		else {
			// key
			if (pq.size()) {
				int cur = pq.top();
				if (cur < pos) return false;
				pq.pop();
			}
		}
	}

	return pq.empty();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> P;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < K; i++) {
		cin >> B[i];
	}

	int lo = 0;
	int hi = 2e9;
	while (lo != hi) {
		int mid = lo + (hi - lo) / 2;
		bool b = solve(mid);
		if (b) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << lo << endl;
	return 0;
}