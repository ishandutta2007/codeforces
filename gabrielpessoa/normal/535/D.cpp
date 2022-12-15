#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 1e6+5;
string p;
int b[ms], valid[ms], n, m, arr[ms];
const ll mod = 1e9 + 7;

void kmpPreprocess() {
	int i = 0, j = -1;
	b[0] = -1;
	while(i < p.size()) {
		while(j >= 0 && p[i] != p[j]) j = b[j];
		b[++i] = ++j;
	}
	j = p.size();
	//cout << "processando " << j << '\n';
	while(j > -1) {
		valid[j] = 1;
		//cout << j << '\n';
		j = b[j];
	}
}

int main(){
	cin >> n >> m >> p;
	kmpPreprocess();
	for(int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	arr[m] = n + 1;
	for(int i = 0; i < m; i++) {
		int entre = max(0, (int) p.size() - (arr[i+1] - arr[i]));
		n -= p.size() - entre;
		if(!valid[entre]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	ll ans = 1;
	while(n--) {
		ans = (ans * 26) % mod;
	}
	cout << ans << '\n';
	return 0;
}