#include <bits/stdc++.h>
using namespace std;

int query(int i, int n){
	if(i > n)i -= n;
	cout << "? " << i << endl;
	int x; cin >> x; return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int x = query(1, n) - query(n/2 + 1, n);
	if(x%2 != 0){
		cout << "! -1" << endl;
		exit(0);
	}
	if(x == 0){
		cout << "! 1" << endl;
		exit(0);
	}
	int l = 1, r = n/2 + 1, lv = x, rv = -x;
	while(l <= r){
		int m = (l + r)/2;
		int val = query(m, n) - query(n/2 + m, n);
		if(val == 0){
			cout << "! " << m << endl;
			exit(0);
		}
		if(val > 0){
			if(lv < 0){
				r = m; rv = val;
			}else{
				l = m; lv = val;
			}
		}else{
			if(lv > 0){
				r = m; rv = val;
			}else{
				l = m; lv = val;
			}
		}
		assert(lv*1LL*rv < 0);
	}

	return 0;
}