#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10100;
const long long Q = 1000010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

typedef complex<double> base;

void fft(vector<base> & a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i<n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}
        long double PI = acos(-1);
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
	for (int i = 0; i<n; ++i)
		a[i] /= n;

}

vector < int > mult(vector < int > a, vector < int > b)
{
        vector < int > res;
	vector < complex < double > > fa(a.begin(), a.end()),  fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size())){
                n *= 2;
	}
	n *= 2;
	fa.resize(n), fb.resize(n);
	fft(fa, false), fft(fb, false);
	for(int i = 0; i < n; i++){
                fa[i] *= fb[i];
	}
	fft(fa, true);
	res.resize(n);
	for(int i = 0; i < n; i++){
                res[i] = int(fa[i].real() + 0.5);
        }
        return res;
}

vector < int > pow(vector < int > v, int n)
{
        if(n == 1){
                return v;
        }
        if(n % 2){
                return mult(v, pow(v, n - 1));
        }
        else{
                return pow(mult(v, v), n / 2);
        }
}

int n, k;
vector < int > v[10];

void dd(vector < int > &v)
{
        while(v.size() > Q){
                v.pop_back();
        }
        for(int j = 0; j < v.size(); j++){
                if(v[j] > 1){
                        v[j] = 1;
                }
        }
}

void solve()
{
        cin >> n >> k;
        v[0].resize(1000 + 10);
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[0][x] = 1;
        }
        for(int i = 1; i < 10; i++){
                v[i] = mult(v[i - 1], v[i - 1]);
                dd(v[i]);
        }
        vector < int > res = v[0];
        for(int i = 0; i < 10; i++){
                if((k - 1) & (1 << i)){
                        res = mult(res, v[i]);
                }
                dd(res);
        }
        for(int i = 0; i < res.size(); i++){
                if(res[i]){
                        cout << i << " ";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}