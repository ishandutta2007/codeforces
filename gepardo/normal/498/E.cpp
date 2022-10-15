#include <iostream>
#include <vector>

using namespace std;

const int MAX_STAIRS = 7;
const int MAT_SIZE = 1 << MAX_STAIRS;
const int MODULO = (int)1e9 + 7;

struct Matrix {
	int mat[MAT_SIZE][MAT_SIZE];
	int maxSize;
	
	Matrix(int sz)
		: maxSize(1 << sz) {
		for (int i = 0; i < MAT_SIZE; i++) {
			for (int j = 0; j < MAT_SIZE; j++) {
				mat[i][j] = 0;
			}
		}
	}
};

struct Xtractor {
	int mat[MAT_SIZE+1] = {};
	
	Xtractor() {
		for (int i = 0; i <= MAX_STAIRS; i++) {
			mat[1 << i] = i;
		}
	}
} xtract;

struct Vector {
	int vec[MAT_SIZE];
	int maxSize;
	
	Vector(int sz)
		: maxSize(1 << sz) {
		for (int i = 0; i < MAT_SIZE; i++) {
			vec[i] = 0;
		}
	}
};

inline Matrix operator*(const Matrix &a, const Matrix &b) {
	int theSz = max(a.maxSize, b.maxSize);
	Matrix res(xtract.mat[theSz]);
	for (int i = 0; i < theSz; i++) {
		for (int j = 0; j < theSz; j++) {
			res.mat[i][j] = 0;
			for (int k = 0; k < theSz; k++) {
				res.mat[i][j] += ((int64_t)a.mat[i][k] * b.mat[k][j]) % MODULO;
				res.mat[i][j] %= MODULO;
			}
		}
	}
	return res;
}

inline Vector operator*(const Vector& a, const Matrix& b) {
	int theSz = max(a.maxSize, b.maxSize);
	Vector res(xtract.mat[theSz]);
	for (int i = 0; i < theSz; i++) {
		res.vec[i] = 0;
		for (int j = 0; j < theSz; j++) {
			res.vec[i] += ((int64_t)a.vec[j] * b.mat[j][i]) % MODULO;
			res.vec[i] %= MODULO;
		}
	}
	return res;
}

inline Matrix oneMatrix(int sz) {
	Matrix res(sz);
	for (int i = 0; i < MAT_SIZE; i++) {
		res.mat[i][i] = 1;
	}
	return res;
}

inline Matrix genTransitionMatrix(int n) {
	Matrix m(n);
	for (int i = 0; i < m.maxSize; i++) {
		for (int j = 0; j < m.maxSize; j++) {
			int all = i & j;
			vector<int> w0(n+1), w1(n+1);
			w0[0] = 0; w1[0] = 1;
			for (int k = 0; k < n; k++) {
				if ((all >> k) & 1) {
					w0[k+1] = (w0[k] + w1[k]) % MODULO;
					w1[k+1] = w0[k];
				} else {
					w0[k+1] = (w0[k] + w1[k]) % MODULO;
					w1[k+1] = (w0[k] + w1[k]) % MODULO;
				}
			}
			m.mat[i][j] = w1[n];
		}
	}
	return m;
}

inline Matrix binPow(Matrix a, int powr, int sz) {
	Matrix res = oneMatrix(sz);
	while (powr != 0) {
		if (powr % 2 == 1) {
			res = res * a;
		}
		a = a * a;
		powr /= 2;
	}
	return res;
}

inline Vector applyOr(const Vector &v, int orVal, int sz) {
	Vector res(sz);
	for (int i = 0; i < res.maxSize; i++) {
		res.vec[i | orVal] += v.vec[i];
		res.vec[i | orVal] %= MODULO;
	}
	return res;
}

int main() {
	vector<int> a(MAX_STAIRS);
	for (int i = 0; i < MAX_STAIRS; i++) {
		cin >> a[i];
	}
	int ptr = 0;
	while (a[ptr] == 0) {
		ptr++;
	}
	Vector v(0);
	v.vec[0] = 1;
	int maxVal = -1;
	for (int i = ptr; i < MAX_STAIRS; i++) {
		if (a[i] == 0) {
			continue;
		}
		int msk = (1 << (i+1)) - (1 << (maxVal+1));
		v = applyOr(v, msk, i+1);
		maxVal = i;
		v = v * binPow(genTransitionMatrix(i+1), a[i], i+1);
	}
	cout << v.vec[(1 << (maxVal+1)) - 1] << endl;
	return 0;
}