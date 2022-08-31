#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll a[100010];
int l, r;
void done() {
	puts("0");
	exit(0);
}
void move_left() {
	while(1) {
		if(l == r) done();
		if(a[l] != a[l + 1]) break;
		l++;
	}
}
void move_right(){
	while(1) {
		if(r == l) done();
		if(a[r] != a[r - 1]) break;
		r--;
	}
}
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	l = 0;
	r = n - 1;
	while(k > 0) {
		move_left();
		move_right();
		int lc = l + 1;
		int rc = n - r;
		if(lc < rc) {
			ll c = a[l + 1] - a[l];
			if(k < c * lc){
				a[0] += k / lc;
				break;
			}
			k -= c * lc;
			a[0] = a[l] = a[l + 1];
		}
		else{
			ll c = a[r] - a[r - 1];
			if(k < c * rc){
				a[n - 1] -= k / rc;
				break;
			}
			k -= c * rc;
			a[n - 1] = a[r] = a[r - 1];
		}
	}
	cout << (a[n - 1] - a[0]) << endl;
	return 0;
}