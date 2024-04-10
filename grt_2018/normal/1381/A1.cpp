#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int t,n;
const int nax = 100 * 1000 + 10;
string a, b;
bool rev;
int start, kon;

char get_c(int x) {
	if(!rev) {
		return a[start + x];
	} else {
		return (1 - (a[kon - x] - '0')) + '0';
	}
}

 
int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> a >> b;
		vi ans = {};
		rev = 0;
		start = 0, kon = n - 1;
		for(int i = n-1; i >=0; --i) {
			if(get_c(i) == b[i]) {
				if(rev) start++;
				else kon--;
				continue;
			}
			if(get_c(0) != b[i]) {
				ans.PB(i + 1);
				rev = 1-rev;
				if(rev) start++;
				else kon--;
			} else {
				ans.PB(1);
				if(rev) a[kon] = (1 - (a[kon] - '0')) + '0';
				else a[0] = (1 - (a[0] - '0')) + '0';
				if(i != 0) {
					ans.PB(i + 1);
				}
				rev = 1 - rev;
				if(rev) start++;
				else kon--;
			}
		}
		cout << (int)ans.size() << " ";
		for(int x : ans) cout << x << " ";
		cout << "\n";
	}
	
}