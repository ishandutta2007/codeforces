#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int N; cin >> N;
	set<string> st;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		cout << (st.count(s) ? "YES" : "NO") << '\n';
		st.insert(s);
	}
	return 0;
}