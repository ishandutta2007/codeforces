#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const string first = "tokitsukaze";
const string second = "quailty";
const string draw = "once again";
int n, k;
char a[100000 + 233];
set<int> S[2];

bool cont(int i, int x, int y) {
	return x <= i && i <= y;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> (a + 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] == '0') S[0].insert(i);
		if(a[i] == '1') S[1].insert(i);
	}
	if(S[0].empty() || *S[0].rbegin() - *S[0].begin() + 1 <= k) {
		cout << first << endl;
		return 0;
	}
	if(S[1].empty() || *S[1].rbegin() - *S[1].begin() + 1 <= k) {
		cout << first << endl;
		return 0;
	}
	bool always = true;
	for(int i = 1; i + k - 1 <= n; ++i) {
		int j = i + k - 1;
		for(int c = 0; c < 2; ++c) {
			bool ok = false;
			for(int d = 0; d < 2; ++d) {
				int L = n + 1, R = 0;
				if(c == d) L = i, R = j;
				auto update = [&](int x) {
					if(!cont(x, i, j)) chmin(L, x), chmax(R, x);
				};
				int x = *S[d].begin();
				update(x);
				x = *S[d].rbegin();
				update(x);
				auto p = S[d].lower_bound(i);
				if(p != S[d].begin()) {
					--p;
					update(*p);
				}
				p = S[d].upper_bound(j);
				if(p != S[d].end()) {
					update(*p);
				}
				if(R - L + 1 <= k) ok = true;
			}
			always &= ok;
		}
	}
	if(always) cout << second << endl;
	else cout << draw << endl;
	return 0;
}