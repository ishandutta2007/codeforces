#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	sort(all(a));
	long long sum = accumulate(all(a), 0ll);
	int avgl = sum / n;
	int avgr = (sum + n - 1) / n;

	vector<long long> evl(1, 0);
	long long cur = 0;
	for (int i = 1; i < n && a[i] <= avgl; i++){
		cur += 1ll * i * (a[i] - a[i - 1]);
		evl.push_back(cur);
	}
	cur = 0;
	vector<long long> evr(1, 0);
	for (int i = n - 2; i >= 0 && a[i] >= avgr; i--){
		cur += 1ll * (n - 1 - i) * (a[i + 1] - a[i]);
		evr.push_back(cur);
	}

	// for (auto x : evl)
	// 	cerr << x << " ";
	// cerr << "\n";

	// for (auto x : evr)
	// 	cerr << x << " ";
	// cerr << "\n";

	int offl;
	int i = 0;
	while (i < evl.size() && evl[i] <= k)
		i++;
	offl = a[i - 1] + (k - evl[i - 1]) / i;
	offl = min(avgl, offl);
	int offr;
	i = 0;
	while (i < evr.size() && evr[i] <= k)
		i++;
	offr = a[n - i] - (k - evr[i - 1]) / i;
	offr = max(avgr, offr);

	// cerr << offl << " " << offr << "\n";

	cout << offr - offl << "\n";

	return 0;
}