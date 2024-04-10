#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define A first
#define B second

const int MOD = 1e9 + 7;

inline void mod(int &a) { if(a >= MOD) a -= MOD; }

const int MAXL = 1.5e6;

const int N = 3;

char S[MAXL];
int L;

struct bit {
	int sz = 1e5;
	int val[MAXL];

	int query(int a) {
		int res = 0;
		for(int i = a; i > 0; i -= i & (-i)) {
			res += val[i];
			mod(res);
		}
		return res;
	}

	//suffix starting at a
	void update(int a, int v) {
		v %= MOD;
		if(v < 0) v += MOD;
		for(int i = a; i <= sz; i += i & (-i)) {
			val[i] += v;
			mod(val[i]);
		}
	}

	void update(int a, int b, int v) {
		update(a, v);
		update(b + 1, -v);
	}
} res;

//suffixes sorted by rank
int suf[MAXL];
//rank of current suffix
int ran[25][MAXL]; // stores rank for each length
int stp = 0; // max length, final row
//lcp of rank i and rank i + 1
int lcp[MAXL];

int getLCP(int a, int b) {
	if(a == b) return L - a;
	int res = 0;
	for(int k = stp; k >= 0 && a <= L && b <= L; k--) {
		if(ran[k][a] == ran[k][b]) {
			a += (1 << k);
			b += (1 << k);
			res += (1 << k);
		}
	}
	return res;
}

// compute suffix array
void getSuffArray() {
	for(int i = 0; i < L; i++) ran[0][i] = S[i];
	memset(lcp, 0, sizeof(lcp));
	for(int len = 1, k = 0; len < L; len *= 2, k++) {
		// len = (1 << k)
		vector<ppi> suffixes;
		for(int i = 0; i < L; i++) {
			pii val;
			val.A = ran[k][i];
			if(i + len < L) val.B = ran[k][i + len];
			else val.B = -1; //short is earlier
			suffixes.push_back(ppi(val, i));
		}
		sort(suffixes.begin(), suffixes.end()); // could do bucket sort
		for(int i = 0, r = 0; i < L; r++) {
			pii val = suffixes[i].A;
			while(i < L && suffixes[i].A == val) {
				ran[k + 1][suffixes[i].B] = r;
				i++;
			}
		}
		stp = k + 1;
	}
	for(int i = 0; i < L; i++) {
		suf[ran[stp][i]] = i;
	}
	for(int i = 0; i + 1 < L; i++) {
		lcp[i] = getLCP(suf[i], suf[i + 1]);
	}
}

int D[N]; //lengths of individual ones
int en[N]; //ending points

int ind[MAXL];
int cnt[N][MAXL]; // prefix counts

int main() {
	L = 0;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		D[i] = s.size();
		for(int j = 0; j < D[i]; j++) {
			S[L++] = s[j];
		}
		en[i] = L;
		S[L++] = '0' + i;
	}

	getSuffArray();


	for(int i = N; i < L; i++) { // skip the first N, which are placeholders
		int v = suf[i];
		ind[i] = 0;
		while(ind[i] + 1 < N && v >= en[ind[i]]) ind[i]++;
		for(int j = 0; j < N; j++) {
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[ind[i]][i] ++;
	}

	/*
	//print suffix array
	for(int i = 0; i < L; i++) {
		for(int j = suf[i]; j < L; j++) {
			cerr << S[j];
		}
		cerr << ' ' << lcp[i] << ' ';
		cerr << ind[i] << '\n';
	}
	*/

	vector<pii> lcps;
	for(int i = N; i + 1 < L; i++) {
		lcps.push_back(pii(lcp[i], i));
	}
	sort(lcps.begin(), lcps.end());

	set<int> endpts;
	endpts.insert(N - 1);
	endpts.insert(L - 1);
	cerr << "hi\n";

	for(int i = 0; i < int(lcps.size()); i++) {
		int v = lcps[i].A;
		int m = lcps[i].B;
		//cerr << v << ' ' << m << '\n';
		auto it = endpts.upper_bound(m);
		int r = *it;
		it--;
		int l = *it;

		ll val = 0;

		ll prod = 1;
		for(int x = 0; x < N; x++) {
			prod *= cnt[x][r] - cnt[x][l];
			prod %= MOD;
		}

		val += prod;

		prod = 1;
		for(int x = 0; x < N; x++) {
			prod *= cnt[x][r] - cnt[x][m];
			prod %= MOD;
		}
		val -= prod;
		prod = 1;
		for(int x = 0; x < N; x++) {
			prod *= cnt[x][m] - cnt[x][l];
			prod %= MOD;
		}
		val -= prod;

		res.update(1, v, val);
		endpts.insert(lcps[i].B);
	}

	//print out the answer
	for(int i = 1; i <= min(D[0], min(D[1], D[2])); i++) {
		if(i > 1) cout << ' ';
		cout << res.query(i);
	}
	cout << '\n';
	return 0;
}