#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

typedef complex<long double> base;

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
        long double PI = acos(-1);
	for (int len=2; len<=n; len<<=1) {
		long double ang = 2*PI/len * (invert ? -1 : 1);
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

void multiply (const vector<long long> & a, const vector<long long> & b, vector<long long> & res) {
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
		res[i] =  (fa[i].real() + 0.5);
}

int n;
int x;
int a[N];

void solve()
{
        cin >> n >> x;
        vector < long long > v(1, 1);
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] < x){
                        a[i] = 1;
                }
                else{
                        a[i] = 0;
                }
                if(a[i] == 0){
                        v[v.size() - 1]++;
                }
                else{
                        v.push_back(1);
                }
        }
        int gg = v.size();
        long long C = 0;
        for(long long x: v){
                C += x * (x - 1) / 2;
        }
        vector < long long > g = v, ans;
        reverse(g.begin(), g.end());
        multiply(v, g, ans);
        while(ans.size() >= gg){
                ans.pop_back();
        }
        ans.push_back(C);
        reverse(ans.begin(), ans.end());
        while(ans.size() <= n){
                ans.push_back(0);
        }
        for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}