#include <bits/stdc++.h>
using namespace std;

const int maxN = 45;

int n, m, uwu, go[maxN][2];
long long mem[maxN][maxN][2];

long long dp(int i, int cur, int flg){
	if(i == n){
		return cur == uwu && flg == 1;
	}
	if(mem[i][cur][flg] != -1)return mem[i][cur][flg];
	
	mem[i][cur][flg] = 0;
	mem[i][cur][flg] += dp(i + 1, go[cur][0], flg||(go[cur][0] == m));
	mem[i][cur][flg] += dp(i + 1, go[cur][1], flg||(go[cur][1] == m));
	return mem[i][cur][flg];
}

void init(){
	cin >> n;
	string s;
	cin >> s;
	m = (int)s.size();

	vector<int> fail(m);
	int i = 1, j = 0;
	while(i < m){
		if(s[i] == s[j]){
			fail[i] = j + 1;
			i++; j++;
		}else if(j){
			j = fail[j - 1];
		}else{
			i++;
		}
	}

	for(int i = 0; i <= m; i++){
		for(int j = 0; j < 2; j++){
			if(i){
				go[i][j] = go[fail[i - 1]][j];
			}else{
				go[i][j] = 0;
			}
		}
		if(i < m){
			go[i][s[i] - '0'] = i + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	long long ans = 0;
	for(int state = 0; state <= m; state++){
		memset(mem, -1, sizeof(mem));
		
		uwu = state;
		ans += dp(0, state, 0);
	}
	cout << ans << '\n';

	return 0;
}