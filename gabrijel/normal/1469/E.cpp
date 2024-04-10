#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int novi_k = min(k, 21), br0 = 0;
		unordered_map <int, bool> imam;
		queue <bool> q;
		REP(i, k - novi_k) br0 += s[i] == '0';
		int ptr = k - novi_k, broj = 0;
		while(ptr < k) {
			q.push(s[ptr] - '0');
			broj *= 2;
			broj += !(s[ptr] - '0');
			ptr++;
		}
		if(!br0) imam[broj] = 1;
		while(ptr < n) {
			br0 -= s[ptr - k] == '0';
			br0 += s[ptr - novi_k] == '0';
			if(!q.front()) broj -= (1 << (novi_k - 1));
			q.pop();
			q.push(s[ptr] - '0');
			broj *= 2;
			broj += !(s[ptr] - '0');
			ptr++;
			if(!br0) imam[broj] = 1;
		}
		int koji = -1;
		REP(i, (1 << novi_k)) {
			if(!imam[i]) {
				koji = i;
				break;
			}
		}
		if(koji == -1) cout << "NO\n";
		else {
			cout << "YES\n";
			REP(i, k - novi_k) cout << "0";
			for(int i = novi_k - 1; i >= 0; i--) {
				if(koji & (1 << i)) cout << "1";
				else cout << "0";
			}
			cout << "\n";
		}
	}
	return 0;
}