#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 101;
const int P = 1e9 + 7;

int n;

struct Matrix {
	int mat[N][N];

	Matrix() { memset(mat, 0, sizeof(mat)); }

	Matrix(const Matrix& x) { memcpy(mat, x.mat, sizeof(mat)); }

	const int* operator[](int k) const { return mat[k]; }

	int* operator[](int k) { return mat[k]; }

	Matrix operator*(const Matrix& x) const {
		Matrix ret = Matrix();
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= i; ++j)
				for (int k = j; k <= i; ++k)
					ret[i][j] = (ret[i][j] + (ll)mat[i][k] * x[k][j] % P) % P;
		return ret;
	}
};

Matrix fibMatrix[N];

int x;
char s[N];

int main() {
	scanf("%d%d%s", &n, &x, s);
	for (int i = 0; i < n; ++i)
		if (s[i] == '0')
			fibMatrix[0][i + 1][i] = 1;
		else
			fibMatrix[1][i + 1][i] = 1;
	for (int i = 1; i < n; ++i)
		fibMatrix[0][i][i] = fibMatrix[1][i][i] = 1;
	fibMatrix[0][0][0] = fibMatrix[1][0][0] = 
	fibMatrix[0][n][n] = fibMatrix[1][n][n] = 2;
	for (int i = 2; i <= x; ++i)
		fibMatrix[i] = fibMatrix[i - 2] * fibMatrix[i - 1];
	printf("%d\n", fibMatrix[x][n][0]);
	return 0;
}