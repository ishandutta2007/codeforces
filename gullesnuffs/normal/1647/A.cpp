#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	int numDigits = (n*2+1)/3;
	int numOnes = numDigits/2;
	while (numOnes+2*(numDigits-numOnes) > n)
		++numOnes;
	bool firstOne = (numOnes*2 > numDigits);
	rep(i,0,numDigits) {
		if (i%2 == !firstOne)
			cout << "1";
		else
			cout << "2";
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}