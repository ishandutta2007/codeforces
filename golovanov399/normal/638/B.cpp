#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void solve(){
	int n = nxt();
	vector<set<int>> a(26);
	vector<set<int>> b(26);
	vector<char> was(26);
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < (int)s.length() - 1; j++){
			a[s[j] - 'a'].insert(s[j + 1] - 'a');
			b[s[j + 1] - 'a'].insert(s[j] - 'a');
		}
		for (int j = 0; j < (int)s.length(); j++)
			was[s[j] - 'a'] = 1;
	}
	vector<string> qw;
	vector<char> used(26);
	for (int i = 0; i < 26; i++){
		if (a[i].size() > 0 && b[i].size() == 0){
			int j = i;
			qw.push_back("");
			while (a[j].size() > 0){
				qw.back() += (char)('a' + j);
				used[j] = 1;
				j = *a[j].begin();
			}
			qw.back() += (char)('a' + j);
			used[j] = 1;
		}
	}
	for (auto s : qw)
		cout << s;
	for (int i = 0; i < 26; i++){
		if (was[i] && a[i].size() == 0 && b[i].size() == 0)
			cout << (char)('a' + i);
	}
	cout << "\n";
}

int main(){

	solve();

	return 0;
}