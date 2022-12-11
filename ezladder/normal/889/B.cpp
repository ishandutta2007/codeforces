#include <bits/stdc++.h>
	 
#define x first
#define y second
#define mp make_pair
#define pub push_back
#define all(a) a.begin(), a.end()
#define ll long long
#define db double
	 
using namespace std;

int n;
string a[100007];
int nxt[26];
bool was[26];
bool can[26];
bool need[26];

int main(){
//	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++){
		set<char> se;
		for (char c : a[i]){
			if (se.find(c) != se.end()) cout << "NO", exit(0);
			se.insert(c);
			need[c - 'a'] = 1;
		}
	}

	for (int i = 0; i < 26; i++) nxt[i] = -1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < (int)a[i].size() - 1; j++){
			int c1 = a[i][j] - 'a';
			int c2 = a[i][j + 1] - 'a';
			if (nxt[c1] != -1 && nxt[c1] != c2) cout << "NO", exit(0);
			nxt[c1] = c2;
		}
		for (int j = 1; j < a[i].size(); j++) can[a[i][j] - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) if (i != j && nxt[i] != -1 && nxt[j] != -1){
		if (nxt[i] == nxt[j]) cout << "NO", exit(0);
	}

	string ans;

	for (int i = 0; i < 26; i++) if (need[i] && !can[i] && !was[i]){
		int v = i;
		while(1){
			if (was[v]) break;
			ans += (char)(v + 'a');
			was[v] = 1;
			v = nxt[v];
			if (v == -1) break;
		}
	}

	for (int i = 0; i < n; i++){
		bool f = 0;
		for (int j = 0; j < ans.size(); j++){
			bool ff = 1;
			for (int s = 0; s < a[i].size(); s++){
				if (j + s >= ans.size()){
					ff = 0;
					break;
				}
				if (a[i][s] != ans[j + s]) ff = 0;
			}		
			if (ff) f = 1;
		}
		if (!f) cout << "NO", exit(0);
	}

	cout << ans;
}