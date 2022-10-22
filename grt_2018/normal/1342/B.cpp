#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t;
string s;

int main() {_
	cin >> t;
	while(t--) {
		cin >> s;
		bool zero = 0, one = 0;
		for(auto x : s) {
			if(x == '1') one = 1;
			else zero = 1;
		}
		if(one & zero) {
			for(int i = 0; i < (int)s.size(); ++i) {
				cout<<"01";
			}
			cout<<"\n";
		} else {
			cout << s << "\n";
		}
	}
}