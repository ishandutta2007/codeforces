#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define debug 0
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 110;
int n;
int ans[nax];
int add[nax];
pair<ll,ll>track[nax], delta[nax];
int inv[100*100*100],p[nax];
int id;

int hidden[nax];

int rand(int a,int b) {
	return a + (rand()%(b-a+1));
}

void query(int x) {
	if(!debug) {
		cout << "+ " << x << "\n";
		add[x]++;
		fflush(stdout);
		pair<ll,ll>w;
		cin >> w.ST >> w.ND;
		id++;
		track[id] = w;
		delta[id].ST = track[id].ST - track[id-1].ST;
		delta[id].ND = track[id].ND - track[id-1].ND;
	} else {
		id++;
		if(id > 0) {
			hidden[x]++;
			add[x]++;
			cout << "+ " << x << "\n";
		}
		int cnt = 0, cnt2 = 0;
		for(int i = 1; i <= n; ++i) {
			if(i!=1&&i!=n) cnt += hidden[i-1] * hidden[i] * hidden[i+1];
			cnt2 += hidden[i] * (hidden[i] - 1) * (hidden[i] - 2) / 6;
		}
		
		track[id].ST = cnt2;
		track[id].ND = cnt;
		if(id > 0) {
			delta[id].ST = track[id].ST - track[id-1].ST;
			delta[id].ND = track[id].ND - track[id-1].ND;
		}
		cout << cnt2 << " " << cnt << "\n";
	}
		
}

int main() {
	srand(time(NULL));
	if(debug) {
		n = rand(4,6);
		cout << "array : (";
		for(int i = 1; i <= n; ++i) {
			hidden[i] = rand(0,n);
			cout << hidden[i] << " ";
		}
		cout << ")\n";
	}
	else cin >> n;
	for(int i = 3; i <= n+4; ++i) {
		p[i] = i * (i-1) * (i-2) / 6;
		inv[p[i] - p[i-1]] = i - 1;
	}
	for(int i = 1; i <= n; ++i) ans[i] = -1;
	if(debug) {
		id = -1;
		query(1);
	}
	else cin >> track[0].ST >> track[0].ND;
	query(1);
	int trzy = -1;
	bool special = 0;
	if(delta[1].ST > 0) ans[1] = inv[delta[1].ST];
	if(ans[1] != -1) {
		query(2);
		if(delta[2].ST > 0) {
			ans[2] = inv[delta[2].ST];
			query(3);
			ans[3] = delta[1].ND / ((ans[2]));
		} else {
			if(delta[2].ND == 0) {
				ans[3] = 0;
				query(2);
				if(delta[3].ST > 0) ans[2] = 1;
				else ans[2] = 0;
				query(3);
			} else {
				if(delta[1].ND > 0) {
					ans[2] = ans[3] = 1;
				} else {
					ans[3] = 1;
					ans[2] = 0;
				}
				query(3);
				if(delta[id].ST > 0) ans[3] = inv[delta[id].ST];
			}
		}
	} else {
		query(2);
		if(delta[2].ST > 0) {
			ans[2] = inv[delta[2].ST];
			query(1);
			if(delta[3].ST > 0) ans[1] = 1;
			else ans[1] = 0;
			query(3);
			if(delta[4].ST > 0) ans[3] = inv[delta[4].ST];
			else {
				if(delta[1].ND == 0) ans[3] = 0;
				else ans[3] = 1;
			}
		} else {
			if(delta[1].ND > 0) {
				ans[2] = 1;
				query(1);
				if(delta[id].ST > 0) ans[1] = 1;
				else ans[1] = 0;
				query(3);
				if(delta[id].ST > 0) ans[3] = inv[delta[id].ST];
				else ans[3] = 1;
			} else {
				if(delta[2].ND > 0) {
					ans[2] = 0;
					ans[3] = 1;
					query(1);
					if(delta[id].ST > 0) ans[1] = 1;
					else ans[1] = 0;
					query(3);
					if(delta[id].ST > 0) ans[3] = inv[delta[id].ST];
				} else {
					ans[3] = 0;
					query(3);
					query(1);
					if(delta[id].ST > 0) ans[1] = 1;
					else ans[1] = 0;
					ans[2] = delta[id].ND - 1;
					add[1]--;
					special = 1;
				}
			}
		}
	}
	trzy = id - special;
	for(int i = 4; i < n; ++i) {
		ll ilo = delta[trzy].ND - (ans[i-2]+add[i-2])*(ans[i-3]+(add[i-3]));
		query(i);
		//cout << "(" << delta[id].ST << ")\n";
		if(delta[id].ST > 0) {
			ans[i] = inv[delta[id].ST];
		} else {
			if(ilo == 0) ans[i] = 0;
			else ans[i] = 1;
		}
		trzy = id;
	}
	if(n > 3) ans[n] = (delta[trzy].ND - (ans[n-2]+add[n-2])*(ans[n-3]+add[n-3]))/(ans[n-2]+add[n-2]);
	cout << "! ";
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	fflush(stdout);
}