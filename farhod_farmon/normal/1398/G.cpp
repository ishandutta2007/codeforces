#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 500500;

using namespace std;

typedef complex<double> base;
double PI = acos(-1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
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
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

int n, x, y;
int a[N], res[Q];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> x >> y;
        vector < int > b(x + 1, 0);
        for(int i = 0; i <= n; i++){
                cin >> a[i];
                b[a[i]] = 1;
        }
        auto c = b;
        reverse(c.begin(), c.end());
        multiply(c, b, b);
        c.resize(x + 1);
        for(int i = 0; i <= x; i++) c[i] = 0;
        for(int i = 0; i < b.size(); i++){
                if(b[i]){
                        c[abs(i - x)] = 1;
                }
        }


        for(int i = 1; i <= x; i++){
                if(!c[i]) continue;
                for(int j = i + y; j < Q; j += (i + y)){
                        res[j] = i + y;
                }
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x;
                cin >> x;
                x /= 2;
                if(res[x]){
                        cout << res[x] * 2 << " ";
                } else{
                        cout << -1 << " ";
                }
        }
}