// Codeforces Round #296 (Div. 1)
// D - Fuzzy Search
// https://codeforces.com/contest/528/problem/D

#include <bits/stdc++.h>
using namespace std;

typedef double ld;

const ld PI = acos(-1);

struct Complex {
	ld real, imag;
	Complex conj() { return Complex(real, -imag); }
	Complex(ld a = 0, ld b = 0) : real(a), imag(b) {}
	Complex operator + (const Complex &o) const { return Complex(real + o.real, imag + o.imag); }
	Complex operator - (const Complex &o) const { return Complex(real - o.real, imag - o.imag); }
	Complex operator * (const Complex &o) const { return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
	Complex operator / (ld o) const { return Complex(real / o, imag / o); }
	void operator *= (Complex o) { *this = *this * o; }
	void operator /= (ld o) { real /= o, imag /= o; }
};

typedef std::vector<Complex> CVector;

const int ms = 1 << 22;

int bits[ms];
Complex root[ms];

void initFFT() {
	root[1] = Complex(1);
	for(int len = 2; len < ms; len += len) {
		Complex z(cos(PI / len), sin(PI / len));
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = root[i] * z;
		}
	}
}

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}


CVector fft(CVector a, bool inv = false) {
	int n = a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				Complex u = a[i + j], v = a[i + j + len] * root[len + j];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}
	if(inv) {
		for(int i = 0; i < n; i++)
			a[i] /= n;
	}
	return a;
}

std::vector<int> mul(const std::vector<int> &a, const std::vector<int> &b) {
	int n = 1;
	while (n - 1 < (int) a.size() + (int) b.size() - 2) n += n;
	CVector poly(n);
	for(int i = 0; i < n; i++) {
		if(i < (int) a.size()) {
			poly[i].real = a[i];
		}
		if(i < (int) b.size()) {
			poly[i].imag = b[i];
		}
	}
	poly = fft(poly);
	for(int i = 0; i < n; i++) {
		poly[i] *= poly[i];
	}
	poly = fft(poly, true);
	std::vector<int> c(n, 0);
	for(int i = 0; i < n; i++) {
		c[i] = (int) (poly[i].imag / 2 + 0.5);
	}
	while (c.size() > 0 && c.back() == 0) c.pop_back();
	return c;
}

int val[300];
int curCount[4];
int qnt[4];
vector<int> a[4];
vector<int> b[4];
vector<int> ans[4];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  initFFT();
  val['A'] = 0;
  val['T'] = 1;
  val['G'] = 2;
  val['C'] = 3;
  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  int lo = 0, hi = 0;
  for(int i = 0; i < n; i++) {
    while(hi < n && hi - i <= k) {
      curCount[val[s[hi++]]]++;
    }
    while(i - lo > k) {
      curCount[val[s[lo++]]]--;
    }
    for(int j = 0; j < 4; j++) {
      a[j].emplace_back(curCount[j] != 0);
    }
  }
  for(int i = 0; i < m; i++) {
    qnt[val[t[i]]]++;
    for(int j = 0; j < 4; j++) {
      b[j].emplace_back(val[t[i]] == j);
    }
  }
  for(int i = 0; i < 4; i++) {
    reverse(b[i].begin(), b[i].end());
  }
  for(int i = 0; i < 4; i++) {
    ans[i] = mul(a[i], b[i]);
    ans[i].resize(n+m);
  }
  int trueAns = 0;
  for(int i = 0; i < n+m; i++) {
    int valid = 1;
    for(int j = 0; j < 4; j++) {
      if(qnt[j] != ans[j][i]) valid = 0;
    }
    trueAns += valid;
  }
  cout << trueAns << "\n";
}