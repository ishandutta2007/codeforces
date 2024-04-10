#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define y second

using namespace std;

string s, t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> s;
	for (char c : s) if (c != 'a') t += c;

	if (t.size() % 2 == 1){
		cout << ":(";
		exit(0);
	}

	for (int i = 0; i < t.size() / 2; i++) if (t[i] != t[i + t.size() / 2]){
		cout << ":(";
		exit(0);
	}

	string ans;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != 'a') cnt++;
		if (cnt == t.size() / 2 + 1){
			for (int j = i; j < s.size(); j++) if (s[j] == 'a'){
				cout << ":(";
				exit(0);
			}
			break;
		}
		ans += s[i];
	}
	cout << ans;
}