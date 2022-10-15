#include <iostream>
#include <vector>

using namespace std;

template<int Modulo>
class Modular {
private:
	int value;
public:
	inline friend Modular binPow(Modular a, int pow) {
		Modular res = 1;
		while (pow) {
			if (pow & 1) {
				res *= a;
			}
			a *= a;
			pow >>= 1;
		}
		return res;
	}
	
	inline friend Modular rev(Modular a) {
		return binPow(a, Modulo - 2);
	}
	
	Modular()
		: value(0) {
	}
	
	Modular(int64_t v)
		: value(v % Modulo)  {
	}
	
	inline Modular& operator=(int64_t b) {
		value = b % Modulo;
		return *this;
	}
	
	inline Modular& operator+=(Modular b) {
		value += b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular& operator-=(Modular b) {
		value += Modulo;
		value -= b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular& operator*=(Modular b) {
		value = ((int64_t)value * b.value) % Modulo;
		return *this;
	}
	
	inline Modular& operator/=(Modular b) {
		return *this *= rev(b);
	}
	
	inline friend Modular operator+(Modular a, Modular b) {
		return a += b;
	}
	
	inline friend Modular operator-(Modular a, Modular b) {
		return a -= b;
	}
	
	inline friend Modular operator*(Modular a, Modular b) {
		return a *= b;
	}
	
	inline friend Modular operator/(Modular a, Modular b) {
		return a /= b;
	}
	
	inline friend ostream &operator<<(ostream &os, Modular a) {
		return os << a.value;
	}
	
	inline int val() {
		return value;
	}
};
typedef Modular<(int)1e9 + 7> ModInt;

int main() {
	const int MAX_FACT = (int)1e6 + 42;
	vector<ModInt> fact(MAX_FACT);
	fact[0] = 1;
	for (int i = 1; i < MAX_FACT; i++) {
		fact[i] = i * fact[i-1];
	}
	
	auto mulSeg = [&](int l, int r) -> ModInt {
		return fact[r] / fact[l-1];
	};
	
	int n, k; cin >> n >> k;
	vector<ModInt> dpYes(n), dpNo(n), dpCur(n);
	
	dpCur[0] = 0;
	dpYes[0] = 0;
	dpNo[0] = 1;
	
	for (int i = 1; i < n; i++) {
		if (i <= k) {
			dpCur[i] = 0;
		} else {
			dpCur[i] = dpNo[i - k - 1] * mulSeg(i - k, i - 1);
		}
		dpYes[i] = dpYes[i-1] * i + dpCur[i];
		dpNo[i] = fact[i] - dpYes[i];
	}
	
	ModInt ans = 0;
	
	for (int i = 0; i < n; i++) {
		ans += dpCur[i] * (n - i) * mulSeg(i + 1, n - 1);
	}
	
	cout << ans << endl;
	return 0;
}