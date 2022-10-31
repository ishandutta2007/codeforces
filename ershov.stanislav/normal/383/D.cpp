#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

const int mod=1e9+7;

int n, res, d1[20020], d2[20020];

int main() {
	cin >> n;
	d1[10010]=1;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		for (int j=0; j<20020; j++) d2[j]=d1[j], d1[j]=0;
		d1[10010]=1;
		for (int j=0; j<20020; j++) if (d2[j]) d1[j-a]=(d1[j-a]+d2[j])%mod, d1[j+a]=(d1[j+a]+d2[j])%mod;
		res=(res+d1[10010]-1)%mod;
	}
	cout << res;
	return 0;
}