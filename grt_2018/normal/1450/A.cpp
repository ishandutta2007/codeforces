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
int n;
string a;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> a;
		string b = "";
		string b2 = "";
		for(int i = 0; i < n; ++i) {
			if(a[i] == 'b') {
				b += "b";
			} else {
				b2 += a[i];
			}
		}
		cout << b + b2 << "\n";
	}
	
}