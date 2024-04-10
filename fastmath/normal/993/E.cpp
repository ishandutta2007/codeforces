#include <bits/stdc++.h>
   
using namespace std; 

#define int long long

const double PI = 3.14159265359;

typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;
 
	vector<base> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft (a0, invert);
	fft (a1, invert);
 
	double ang = 2*PI/n * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
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
		res[i] = (long long)(fa[i].real() + 0.5);
}

const int MAXN = 2e5 + 7;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
	 	cin >> a[i];
	}

	int last = -1;
	vector <int> p;
	int t = 0;
	for (int i = 0; i < n; ++i) {
	    if (a[i] < x) {
	        p.push_back(i - last);
	        int len = i - last - 1;
	        t += len * (len + 1) / 2;
	        last = i;
	        
	    }	
	}	
	p.push_back(n - last);
	int len = n - last - 1;
	t += len * (len + 1) / 2;
	
	vector <int> rp = p;
	reverse(rp.begin(), rp.end());

	vector <int> ans(2 * MAXN);

	multiply(p, rp, ans);

	cout << t << ' ';
	for (int i = p.size(); i <= p.size() - 1 + n; ++i) {
	 	cout << ans[i] << ' ';
	}
	cout << '\n';

    return 0;
}