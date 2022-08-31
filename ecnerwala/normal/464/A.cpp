#include<bits/stdc++.h>

using namespace std;

int N, P;
char S[2000];

// increment position a
bool inc(int a) {
	if(a < 0) return false;
	S[a] ++;
	if(S[a] == 'a' + P) {
		if(inc(a - 1)) {
			S[a] = 'a' - 1;
			return inc(a);
		} else {
			return false;
		}
	} else {
		if(a - 1 >= 0 && S[a] == S[a - 1]) return inc(a);
		if(a - 2 >= 0 && S[a] == S[a - 2]) return inc(a);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> P;
	cin >> S;
	if(inc(N - 1)) cout << S << '\n';
	else cout << "NO\n";
	return 0;
}