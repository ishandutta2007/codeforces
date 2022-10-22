#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt[30] = {};
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for (char c : s){
			cnt[c - 'a'] += 1;
		}
	}
	bool chk = true;
	for (int i = 0; i < 26; i++){
		if (cnt[i] % n != 0){ chk = false; }
	}
	if (chk){ cout << "YES" << endl; }
	else{ cout << "NO" << endl; }
}

int main(){
	FastIO;
	int t; cin >> t;
	while (t--){ solve(); }
}