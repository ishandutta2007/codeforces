#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2e5+5, mv = 2e5+5, nove = 1e9;
const ll mod = 1e9+7;

set<int> s;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for(auto x : s) {
		for(int i = 0; i < 30; i++) {
			int k = 1 << i;
			if(x <= nove - k - k) {
				//cout << "Testing " << x << " " << k << endl;
				if(s.count(x+k) && s.count(x+k+k)) {
					cout << 3 << endl << x << ' ' << x + k << ' ' << x + k + k << endl;
					return 0;
				}
			}
		}
	}
	for(auto x : s) {
		for(int i = 0; i < 31; i++) {
			int k = 1 << i;
			if(x <= nove - k) {
				if(s.count(x+k)) {
					cout << 2 << endl << x << ' ' << x + k << endl;
					return 0;
				}
			}
		}
	}
	cout << 1 << endl << *s.begin() << endl;
	return 0;
}