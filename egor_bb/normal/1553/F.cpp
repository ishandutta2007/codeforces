#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAX_N = 1 << 19;
const int SQRT = 1;

ll t[MAX_N], tSum[MAX_N], tCnt[MAX_N];

ll get(int ind) {
	ll res = 0;
	for (; ind >= 0; ind &= (ind + 1), ind--)
		res += t[ind];
	return res;
}

void add(int ind, int n, int val) {
	for (; ind < n; ind |= (ind + 1))	
		t[ind] += val;
}

void addSum(int ind, int n, int val) {
	for (; ind < n; ind |= (ind + 1)) {
		tSum[ind] += val;
		tCnt[ind]++;
	}
}

ll getSum(int ind) {
	ll res = 0;
	for (; ind >= 0; ind &= (ind + 1), ind--)
		res += tSum[ind];
	return res;
}

ll getCnt(int ind) {
	ll res = 0;
	for (; ind >= 0; ind &= (ind + 1), ind--)
		res += tCnt[ind];
	return res;
}

ll sum(int l, int r) { // [l, r)
	return get(r - 1) - get(l - 1);
}

int cntMod[SQRT];
ll sumMod[SQRT];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int cntSmall = 0, cntLarge = 0;
	ll ans = 0;
	forn(q, n) {
		int x;
		cin >> x;
		// x mod small
		forab(i, 1, SQRT) {
			ans += cntMod[i] * 1ll * (x % i);
			sumMod[i] += (x % i);
		}
		// x mod large
		ans += x * 1ll * cntLarge - sum(0, x + 1);
		
		if (x < SQRT) {
			// ? mod small x
			cntSmall++;
			cntMod[x]++;
			ans += sumMod[x];
		} else {
			// ? mod large x
			cntLarge++;
			for(int i = 0; i < MAX_N; i += x) {
				if (i) {
					add(i, MAX_N, x);
				}
				int r = min(i + x, MAX_N);
				int totalCnt = getCnt(r - 1) - getCnt(i);
				ll totalSum = getSum(r - 1) - getSum(i);
				ans += totalSum - totalCnt * 1ll * i;
			}
			
		}
		addSum(x, MAX_N, x);
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}