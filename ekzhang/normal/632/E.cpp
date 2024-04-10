#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v =split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

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

#define MAXN 1013
int N, K;


void fft(ftype* A, int n, bool inv=false) {
	assert(__builtin_popcount(n) == 1);
	for (int i = 1, j = n / 2; i + 1 < n; i++) {
		if (i < j) swap(A[i], A[j]);
		int t = n / 2;
		while (j >= t) j -= t, t >>= 1;
		j += t;
	}
	for (int h = 2; h <= n; h <<= 1) {
		ftype wm(cos(2 * PI / h), sin(2 * PI / h));
		for (int i = 0; i < n; i += h) {
			ftype w(1);
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

vector<int> multiply(vector<int> p, vector<int> q) {
	int dim = p.size() + q.size() - 1;
	while (__builtin_popcount(dim) != 1) ++dim;
	ftype* a = new ftype[dim];
	ftype* b = new ftype[dim];
	for (int i = 0; i < p.size(); i++) {
		a[i] = p[i];
	}
	for (int i = 0; i < q.size(); i++) {
		b[i] = q[i];
	}
	fft(a, dim);
	fft(b, dim);
	for (int i = 0; i < dim; i++) {
		a[i] = a[i] * b[i];
	}
	delete[] b;
	fft(a, dim, true);
	vector<int> res(dim);
	for (int i = 0; i < dim; i++) {
		res[i] = (bool) round(a[i].real);
	}
	while (!res.back()) res.pop_back();
	delete[] a;
	return res;
}

vector<int> ppow(vector<int> p, int n) {
	if (!n) return { true };
	vector<int> q = ppow(p, n / 2);
	q = multiply(q, q);
	if (n % 2) q = multiply(p, q);
	return q;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	vector<int> p(1013);
	for (int i = 0; i < N; i++) {
		int P; cin >> P;
		p[P] = 1;
	}

	vector<int> ans = ppow(p, K);
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i]) {
			cout << i << ' ';
		}
	}

	cout << endl;
	return 0;
}