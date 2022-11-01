//FFT 2D
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
typedef complex<double> doublex;

void FFT(vector<doublex> &a, bool inverse) {
    int n = a.size();
    assert(n == (n & -n));

	vector<int> rev(n);
    for(int i = 1; i < n; ++i) {
        rev[i] = (rev[i>>1]>>1) | (i&1 ? n>>1 : 0);
        if (rev[i] < i) swap(a[i], a[rev[i]]);
    }

	for(int m = 2; m <= n; m <<= 1) {
		double theta = (inverse? -1 : 1) * 2 * PI / m;
		doublex unity_root(cos(theta), sin(theta));

		for(int k = 0; k < n; k += m) {
			doublex omega = 1;

			for(int j = 0; j < m/2; j++) {
				doublex t = a[k + j + m/2] * omega;
				doublex u = a[k + j];

				a[k + j] = u + t;
				a[k + j + m/2] = u - t;
				omega *= unity_root;
			}
		}
	}
    for(int j = 0; inverse && j < n; j++) a[j] /= n;
}

vector<vector<doublex>> multiply2D(vector<vector<doublex>> &a, vector<vector<doublex>> &b) {
    int n, m;

    for(n = 1; n < 2*max(a.size(), b.size()); n <<= 1);
    a.resize(n); b.resize(n);

    for(m = 1; m < 2*max(a[0].size(), b[0].size()); m <<= 1);
    for(int i = 0; i < a.size(); i++) a[i].resize(m);
    for(int i = 0; i < b.size(); i++) b[i].resize(m);

    for(int i = 0; i < n; i++) {
        FFT(a[i], false);
        FFT(b[i], false);
    }

    for(int j = 0; j < m; j++) {
        vector<doublex> col(n);
        for(int i = 0; i < n; i++) col[i] = a[i][j];
        FFT(col, false);
        for(int i = 0; i < n; i++) a[i][j] = col[i];

        for(int i = 0; i < n; i++) col[i] = b[i][j];
        FFT(col, false);
        for(int i = 0; i < n; i++) b[i][j] = col[i];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] *= b[i][j];

    for(int j = 0; j < m; j++) {
        vector<doublex> col(n);
        for(int i = 0; i < n; i++) col[i] = a[i][j];
        FFT(col, true);
        for(int i = 0; i < n; i++) a[i][j] = col[i];
    }

    for(int i = 0; i < n; i++) {
        FFT(a[i], true);
    }
    return a;
}

vector<vector<int>> matching2D(vector<string> &a, vector<string> &b) {
    vector<vector<doublex>> da(a.size()), db(b.size(), vector<doublex>(b[0].size())), c;

    for(int i = 0; i < a.size(); i++) {
        da[i].resize(a[i].size());
        for(int j = 0; j < a[i].size(); j++) {
            int value = a[i][j] - 'a';
            da[i][j] = {cos(2*PI*value/26), sin(2*PI*value/26)};
        }
    }

    int letters = 0;
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b[i].size(); j++) {
            int value = b[i][j] - 'a';
            if(b[i][j] != '?') {
                db[b.size()-i-1][b[i].size()-j-1] = {cos(-2*PI*value/26), sin(-2*PI*value/26)};
                letters++;
            }
        }
    }
    c = multiply2D(da, db);

    vector<vector<int>> ret(a.size());
    for(int i = 0; i < a.size(); i++) {
        ret[i].resize(a[i].size());
        for(int j = 0; j < a[i].size(); j++) {
            if(abs(c[i+b.size()-1][j+b[0].size()-1].real() - letters) < 1e-6) ret[i][j] = 1;
        }
    }
    return ret;
}

int n, m, r, c, x;
char s[440]; string str[440], str2;

int main() {
    vector<string> a, b;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", s); str[i] = s;
        a.push_back(str[i]);
    }

    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        scanf("%s", s); str2 = s;
        b.push_back(str2);
    }

    while(a[0].size() < c)
        for(int i = 0; i < a.size(); i++)
            a[i] = a[i] + str[i];

    while(a.size() < r)
        for(int i = 0; i < n; i++)
            a.push_back(a[i]);

    for(int i = 0; i < a.size(); i++)
        a[i] = a[i] + a[i];
    for(int i = 0, sz = a.size(); i < sz; i++)
        a.push_back(a[i]);

    vector<vector<int>> ret = matching2D(a, b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d", ret[i][j]);
        puts("");
    }
	return 0;
}