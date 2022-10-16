/*input
0 1 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long sk;
	cin >> sk;
	if(sk==0){
		cout << 0;
		return 0;
	}
	vector<bool> bi;

	while (sk > 0) {
		bi.push_back(sk % 2ll);
		sk /= 2ll;
	}

	reverse(bi.begin(), bi.end());

	/*vector<bool> gaut;
	for(int i = 0; i < bi.size(); i++) {
		gaut.push_back(bi[i]);
		gaut.insert(gaut.end(),gaut.begin(),gaut.end()-1);
	}*/

	long long l, r;
	cin >> l >> r;
	long long c = 0;

	while (l <= r) {
		long long t = l++;
		int k = 0;

		while (t % 2ll == 0ll) {
			k++;
			t /= 2ll;
		}

		c += bi[k];
	}

	cout << c << endl;
	return 0;
}