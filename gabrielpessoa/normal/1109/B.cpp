	#include<bits/stdc++.h>
	using namespace std;

	typedef long long ll;
	typedef pair<int, int> ii;
	typedef vector<int> vi;
	typedef vector<ii> vii;

	const int ms = 3e5+5;
	const int inf = 0x3f3f3f3f;

	int a[ms];

	int main() {
		cin.tie(0); ios::sync_with_stdio(0);
		string s;
		cin >> s;
		int n = s.size();
		bool tudoIgual = 1;
		for(int i = 1; i < n/2; i++) {
			if(s[i] != s[i-1]) tudoIgual = 0;
		}
		bool daComUm = 0;
		for(int i = 1; i < n; i++) {
			bool eq = 1;
			bool palin = 1;
			for(int j = 0; j < n; j++) {
				int jj = (i+j)%n;
				int kk = (i+(n-j-1)) % n;
				if(s[jj] != s[j]) eq = 0;
				if(s[jj] != s[kk]) palin = 0;
			}
			if(palin && !eq) daComUm = 1;
		}
		if(tudoIgual) {
			cout << "Impossible\n";
		} else if(daComUm) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}