#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef complex <double> base;

int n;

int rev(int k, int siz) {
    int sol = 0, log = log2(siz)-1;
    while (k) {
        if (k & 1)
            sol += 1 << log;
        k >>= 1;
        log--;
    }
    return sol;
}

void FFT(vector<base> &a, bool inverse) {
    int n = a.size();
    if(n == 1) return;

    for(int i=0; i<n; i++)
        if(i < rev(i, n))
            swap(a[i], a[rev(i,n)]);

    for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (inverse ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (inverse)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<ll> multiply(vector<int> &a, vector<int> &b) {
    vector<base> fa(a.begin(), a.end()),fb(b.begin(), b.end());

    int n = 1;
    while(n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;

    fa.resize(n), fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);
    for(int i=0; i<n; i++)
        fa[i] *= fb[i];
    FFT(fa, true);

    vector<ll> res(n);
    for(int i=0; i<n; i++)
        res[i] = ll(fa[i].real() + 0.5);

    return res;
}

int ss, ts, k;
char s[200200], t[200200];

int main() {
    scanf("%d %d %d", &ss, &ts, &k);
    scanf("%s %s", s, t);

    string alp = "ACGT";
    vector<int> b[4][2];
    vector<ll> res[4];

    for(int i = 0; i < 4; i++) {
        char c = alp[i];
        b[i][0].resize(ss);
        b[i][1].resize(ts);

        for(int j = 0; j < ss; j++) {
            if(s[j] == c) {
                if(j + k + 1 < ss) b[i][0][j + k + 1]--;
                b[i][0][max(0, j - k)]++;
            }
        }

        for(int j = 1; j < ss; j++) {
            b[i][0][j] += b[i][0][j-1];
        }

        for(int j = 0; j < ss; j++) {
            b[i][0][j] = (b[i][0][j] > 0);
        }

        for(int j = 0; j < ts; j++) {
            b[i][1][j] = (t[j] == c);
        }

        reverse(b[i][0].begin(), b[i][0].end());
        res[i] = multiply(b[i][0], b[i][1]);
    }

    int ans = 0;
    for(int i = 0; i < res[0].size(); i++) {
        if(res[0][i] + res[1][i] + res[2][i] + res[3][i] == ts) ans++;
    }

    printf("%d\n", ans);

    return 0;
}