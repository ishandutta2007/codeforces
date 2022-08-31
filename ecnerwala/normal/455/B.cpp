#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 20;
const int MAXC = 1e5 + 20;

int N;

int K;

int C;
int nxt[MAXC][26];

bool canwin[MAXC];
bool canlose[MAXC];

int main() {
	ios_base::sync_with_stdio(0);
	memset(nxt, -1, sizeof(nxt));
	cin >> N >> K;
	C = 1;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		int cur = 0;
		for(char c : s) {
			int v = c - 'a';
			if(nxt[cur][v] == -1) {
				nxt[cur][v] = C++;
			}
			cur = nxt[cur][v];
		}
	}
	for(int i = C - 1; i >= 0; i--) {
		bool isLeaf = true;
		for(int v = 0; v < 26; v++) {
			if(nxt[i][v] != -1) {
				isLeaf = false;
			}
		}
		if(isLeaf) {
			canwin[i] = false;
			canlose[i] = true;
		} else {
			canwin[i] = canlose[i] = false;
			for(int v = 0; v < 26; v++) {
				if(nxt[i][v] != -1) {
					if(!canwin[nxt[i][v]]) canwin[i] = true;
					if(!canlose[nxt[i][v]]) canlose[i] = true;
				}
			}
		}
	}

	cerr << canwin[0] << ' ' << canlose[0] << '\n';

	if(canwin[0] && canlose[0]) {
		cout << "First\n";
	} else if(canwin[0]) {
		if(K % 2 == 1) {
			cout << "First\n";
		} else {
			cout << "Second\n";
		}
	} else if(canlose[0]) {
		cout << "Second\n";
	} else {
		cout << "Second\n";
	}
	return 0;
}