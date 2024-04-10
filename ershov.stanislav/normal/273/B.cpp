#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> a, b, c;
ll n, m, ans=1, p2;

int main() {
	cin >> n;
	a.resize(n), b.resize(n), c.resize(2*n);
	for (int i=0; i<n; i++) cin >> a[i], c[i]=a[i];
	for (int i=0; i<n; i++) cin >> b[i], c[i+n]=b[i];
	cin >> m;
	sort(c.begin(), c.end());
	int last=-1, mult=1;
	for (int i=0; i<2*n; i++) {
		if (c[i]!=last) {
			last=c[i];
			mult=1;
			continue;
		}
		mult++;
		int m2=mult;
		while (!(m2%2)) m2/=2, p2++;
		ans*=m2;
		ans%=m;
	}
	for (int i=0; i<n; i++) if (a[i]==b[i]) p2--;
	for (int i=0; i<p2; i++) ans*=2, ans%=m;
	cout << ans;
	return 0;
}