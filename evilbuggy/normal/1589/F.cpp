#include <bits/stdc++.h>
using namespace std;

const int maxK = 52;
const int maxN = 15;
const int maxL = 205;

string s[maxN];
map<vector<int>, int> mem;
map<vector<int>, int> nch;
int n, len[maxN], nxt[maxN][maxL][maxK];

int dp(vector<int> &state){
	if(mem.count(state))return mem[state];

	int ret = 0, rch = 0;
	for(int ch = 0; ch < maxK; ch++){
		vector<int> nstate = state;
		
		bool flg = true;
		for(int i = 0; i < n; i++){
			nstate[i] = nxt[i][state[i] + 1][ch];
			if(nstate[i] == len[i])flg = false;
		}
		if(flg){
			int tmp = dp(nstate) + 1;
			if(ret < tmp){
				ret = tmp;
				rch = ch;
			}
		}
	}
	nch[state] = rch;
	return mem[state] = ret;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		len[i] = (int)s[i].size();
		for(int ch = 0; ch < maxK; ch++){
			nxt[i][len[i]][ch] = len[i];
		}
		for(int j = len[i] - 1; j >= 0; j--){
			for(int ch = 0; ch < maxK; ch++){
				nxt[i][j][ch] = nxt[i][j + 1][ch];
			}
			int ch = -1;
			if('a' <= s[i][j] && s[i][j] <= 'z')ch = s[i][j] - 'a';
			if('A' <= s[i][j] && s[i][j] <= 'Z')ch = s[i][j] - 'A' + 26;
			nxt[i][j][ch] = j;
		}
	}
	mem.clear();
	nch.clear();
	vector<int> state(n, -1);
	
	string lcs = "";
	int answer = dp(state);
	for(int i = 0; i < answer; i++){
		int ch = nch[state];
		for(int i = 0; i < n; i++){
			state[i] = nxt[i][state[i] + 1][ch];
		}
		if(ch < 26)lcs += char(ch + 'a');
		else lcs += char(ch - 26 + 'A');
	}
	cout << answer << '\n' << lcs << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}