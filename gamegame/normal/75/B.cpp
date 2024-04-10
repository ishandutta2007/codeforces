#include <bits/stdc++.h>
#define ll long long
using namespace std; 

string s1,s2,s3,s4,s5;
map<string, int> mp, score;
string ar[500];
pair<int,string> ans[500];
int n,m,k, id = 2;


void solve() {
	cin >> s1;
	mp[s1] = 1;
	ar[1] = s1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		if (s2 != "likes") cin >> s3;
		cin >> s4 >> s5;
		s4 = s4.substr(0,s4.length()-2);
		if (!mp[s1]) {
			mp[s1] = id;
			ar[id++] = s1;
		}
		if (!mp[s4]) {
			mp[s4] = id;
			ar[id++] = s4;
		}
		if(mp[s1]!=1 && mp[s4]!=1) continue;
		if (s2 == "posted") {
			score[ar[mp[s1]]] += 15;
			score[ar[mp[s4]]] += 15;
		} else if (s2 == "commented") {
			score[ar[mp[s1]]] += 10;
			score[ar[mp[s4]]] += 10;			
		} else {
			score[ar[mp[s1]]] += 5;
			score[ar[mp[s4]]] += 5;			
		}
	}
	for (int i = 1; i < id; i++) {
		ans[i] = {-score[ar[i]],ar[i]};
	}
	sort(ans+1,ans+id);
	for (int i = 1; i < id; i++) if (ans[i].second != ar[1]) cout << ans[i].second << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int T;
//	cin >> T;
	T = 1;
	while (T--) {
		solve();
	}
}