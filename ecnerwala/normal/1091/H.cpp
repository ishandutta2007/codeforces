#include<bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif
using namespace std;

const int MAXN = 1.1e5;
const int MAXF = int(2e5) + 20;
const int MAXD = int(2e5) + 20;
//const int MAXD = 2000;

int F;
int nimber[MAXD];

char good[MAXD];
vector<int> invNimber[100];
bool exc[100][MAXD];

template <int L_, typename num> struct fft {
	static constexpr int L = L_;
	static constexpr int N = (1 << L);
	using num_t = num;

	using arr = num[N];
	const num root;
	const num invRoot = num(1) / root;
	const num invN = num(1) / num(N);
	num roots[L+1];
	num invRoots[L+1];
	fft(num root_) : root(root_) {
		roots[0] = root;
		invRoots[0] = invRoot;
		for (int i = 1; i <= L; i++) {
			roots[i] = roots[i-1] * roots[i-1];
			invRoots[i] = invRoots[i-1] * invRoots[i-1];
		}
		//assert(roots[L] == 1);
		//assert(invRoots[L] == 1);
	}

	void bitReversal(arr a) {
		for (int i = 1, j = 0; i < N-1; i++) {
			for (int k = N / 2; k > (j ^= k); k /= 2);
			if (j < i) {
				std::swap(a[j], a[i]);
			}
		}
	}

	void operator () (arr a, bool inv = false) {
		bitReversal(a);
		for (int l = 1, p = 0; l < N; l <<= 1, p++) {
			num w = inv ? invRoots[L - p - 1] : roots[L - p - 1];
			for (int k = 0; k < N; k += (2 * l)) {
				num v = 1;
				for (int i = k; i < k + l; i++, v *= w) {
					num x = a[i];
					num y = v * a[i+l];
					a[i] = x + y;
					a[i+l] = x - y;
				}
			}
		}
		if (inv) {
			for (int i = 0; i < N; i++) {
				a[i] *= invN;
			}
		}
	}
};

using cfft_t = fft<18, complex<double>>;
cfft_t cfft(std::polar(1., 2 * M_PI / (1 << 18)));
cfft_t::arr ac;
cfft_t::arr bc;

void precomp() {
	for (int p = 2; p < MAXD; p++) {
		if (good[p]) continue;
		for (int j = p; j < MAXD; j += p) {
			for (int v = j; good[j] <= 2 && v % p == 0; v /= p) {
				good[j] ++;
			}
		}
		assert(good[p]);
	}
	// mark it as too many factors
	for (int i = 0; i < MAXD; i++) {
		good[i] = (good[i] <= 2);
		bc[i] = good[i];
	}
	good[0] = good[1] = good[F] = false;
	int numGood = 0;
	for (int i = 0; i < MAXD; i++) {
		numGood += good[i];
	}
	cfft(bc);

	int curMax = 0;
	for (int i = 0; i < MAXD; i++) {
		/*
		for (int j = 2; j <= i; j++) {
			if (good[j]) {
				exc[nimber[i-j]] = true;
			}
		}
		nimber[i] = 0;
		while (exc[nimber[i]]) nimber[i]++;
		for (int j = 2; j <= i; j++) {
			if (good[j]) {
				exc[nimber[i-j]] = false;
			}
		}
		*/

		nimber[i] = 0;
		while (true) {
			bool found = exc[nimber[i]][i];
			for (auto it = invNimber[nimber[i]].begin(); !found && it != invNimber[nimber[i]].end(); it++) {
				if (good[i - *it]) {
					found = true;
					break;
				}
			}

			if (found) {
				nimber[i]++;
			} else {
				break;
			}
		}
		invNimber[nimber[i]].push_back(i);
		/*
		if (false && invNimber[nimber[i]].size() >= 1000) {
			cerr << "clearing " << nimber[i] << '\n';
			memset(ac, 0, sizeof(ac));
			for (int v : invNimber[nimber[i]]) {
				ac[v] = 1;
			}
			cfft(ac);
			for (int z = 0; z < cfft_t::N; z++) {
				ac[z] *= bc[z];
			}
			cfft(ac, true);
			for (int v = i+1; v < MAXD; v++) {
				if (ac[v].real() > 0.5) {
					exc[nimber[i]][v] = true;
				}
			}
			invNimber[nimber[i]].clear();
		}

		if (i <= 1000 || nimber[i] > curMax) {
			cerr << i << ' ' << nimber[i] << '\n';
		}


		if (i == 1000) {
			for (int v = 0; v <= curMax; v++) {
				cerr << v << ' ' << invNimber[v].size() << ":";
				for (int a : invNimber[v]) cerr << ' ' << a;
				cerr << '\n';
			}
		}
		*/

		curMax = max(curMax, nimber[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N >> F;
	precomp();

	int res = 0;
	for (int i = 0; i < N; i++) {
		int b, w, r; cin >> b >> w >> r;
		assert(w > b);
		res ^= nimber[w-b-1];
		assert(r > w);
		res ^= nimber[r-w-1];
	}
	cerr << res << '\n';
	// first mover wins
	if (res) {
		cout << "Alice\nBob\n";
	} else {
		cout << "Bob\nAlice\n";
	}

	return 0;
}