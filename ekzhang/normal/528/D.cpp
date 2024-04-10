#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

template <typename T>
struct Complex {
	T real, imag;
	Complex(T x=(T)0, T y=(T)0) : real(x), imag(y) {}
	Complex conj() { return Complex(real, -imag); }
	Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
	Complex operator-(const Complex& c) { return Complex(real - c.real, imag - c.imag); }
	Complex operator*(const T& num) { return Complex(real * num, imag * num); }
	Complex operator/(const T& num) { return Complex(real / num, imag / num); }
	Complex operator*(const Complex& c) {
		return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
	}
	Complex operator/(const Complex& c) {
		return *this * c.conj() / (c.x * c.x + c.y * c.y);
	}
};
typedef Complex<double> ftype;
const double PI = 4 * atan(1);
#define MAX 524288
int N, M, K;
string S, T;
int dim;
bool ans[MAX];

ftype P[MAX], Q[MAX];
int R[MAX];

// template<typename T>
// void fft(T* in, ftype* out, int n, int k=1) {
// 	if (n == 1) {
// 		*out = *in;
// 		return;
// 	}
// 	int t = dim / n;
// 	n >>= 1;
// 	fft(in, out, n, k * 2);
// 	fft(in + k, out + n, n, k * 2);
// 	for (int i = 0, j = 0; i < n; i++, j += t) {
// 		ftype x = w[j] * out[i + n];
// 		out[i + n] = out[i] - x;
// 		out[i] += x;
// 	}
// }

void fft(ftype* A, int n, bool inv=false) {
	for (int i = 1, j = n / 2; i < n - 1; i++) {
		if (i < j) swap(A[i], A[j]);
		int k = n / 2;
		while (j >= k) j -= k, k >>= 1;
		j += k;
	}
	for (int h = 2; h <= n; h <<= 1) {
		ftype wm(cos(2 * PI / h), sin(2 * PI / h));
		for (int i = 0; i < n; i += h) {
			ftype w = 1;
			for (int j = i; j < i + h / 2; j++) {
				ftype x = A[j], y = w * A[j + h / 2];
				A[j + h / 2] = x - y;
				A[j] = x + y;
				w = w * wm;
			}
		}
	}
	if (inv) {
		reverse(A + 1, A + n);
		for (int i = 0; i < n; i++) {
			A[i] = A[i] / n;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K >> S >> T;
	memset(ans, true, sizeof ans);

	dim = N + M - 1;
	while (__builtin_popcount(dim) != 1) ++dim;

	for (char c : {'A', 'G', 'C', 'T'}) {
		memset(P, 0, sizeof P);
		memset(Q, 0, sizeof Q);

		int pre = -MAX;
		for (int i = 0; i < N; i++) {
			if (S[i] == c) pre = i;
			if (i - pre <= K) P[i] = 1;
		}
		pre = MAX + N;
		for (int i = N - 1; i >= 0; i--) {
			if (S[i] == c) pre = i;
			if (pre - i <= K) P[i] = 1;
		}
		int tq = 0;
		for (int i = 0; i < M; i++) {
			Q[M - 1 - i] = T[i] == c;
			tq += T[i] == c;
		}

		fft(P, dim);
		fft(Q, dim);

		for (int i = 0; i < dim; i++) {
			P[i] = P[i] * Q[i];
		}

		fft(P, dim, true);

		for (int i = 0; i < dim; i++) {
			R[i] = round(P[i].real);
		}
		for (int i = 0; i < dim; i++) {
			if (R[i] != tq)
				ans[i] = false;
		}
	}

	cout << accumulate(ans, ans + dim, 0) << endl;
	return 0;
}