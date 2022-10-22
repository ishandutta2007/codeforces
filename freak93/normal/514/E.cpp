#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

const int kModulo = 1000 * 1000 * 1000 + 7;

vector< vector<int> > mul(vector< vector<int> > a, vector< vector<int> > b) {
    int N = a.size();
    int M = b.size();
    int P = b[0].size();
    vector< vector<int> > c(N, vector<int>(P, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < P; ++k)
                c[i][k] = (c[i][k] + 1LL * a[i][j] * b[j][k]) % kModulo;
    return c;
}

int main() {
    ios::sync_with_stdio(false);

    int N, X; cin >> N >> X;
    vector< vector<int> > z(101, vector<int>(101, 0));
    vector< vector<int> > base(1, vector<int>(101, 0));
    base[0][0] = 1;

    for (int i = 0; i < 99; ++i)
        z[i + 1][i] = 1;
    z[100][100] = 1;
    z[0][100] = 1;

    for (int i = 0; i < N; ++i) {
        int d; cin >> d;
        z[0][d - 1] += 1;
    }

    while (X > 0) {
        if (X % 2)
            base = mul(base, z);
        z = mul(z, z);
        X /= 2;
    }
    cout << (base[0][0] + base[0][100]) % kModulo << "\n";
}