#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	string s;
	cin >> s;
	int n = s.length();
	vector<char> ok[2];
	for (int i = 0; i < 2; i++)
		ok[i].resize(n);
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < 2; j++){
			if (i + 2 + j <= n && (i + 2 + j == n || ok[1 - j][i + 2 + j] || (ok[j][i + 2 + j] && s.substr(i, 2 + j) != s.substr(i + 2 + j, 2 + j))))
				ok[j][i] = true;
		}
	}

	vector<string> S;
	for (int i = 5; i < n; i++){
		for (int j = 0; j < 2; j++){
			if (ok[j][i]){
				S.push_back(s.substr(i, 2 + j));
			}
		}
	}

	sort(all(S));
	S.resize(unique(all(S)) - S.begin());
	cout << S.size() << "\n";
	for (auto x : S)
		cout << x << "\n";

	return 0;
}