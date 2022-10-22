#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10, INF = 1e9;
int n;
int mi[nax], smi[nax];
bool pr[nax];
int ile[nax];

void factor(int x) {
	//vector<pi>res = {};
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			int cnt = 1;
			x /= i;
			while(x % i == 0) {
				x /= i;
				cnt++;
			}
			if(mi[i] >= cnt) {
				smi[i] = mi[i];
				mi[i] = cnt;
			} else if(smi[i] > cnt) {
				smi[i] = cnt;
			}
			//~ cout << i << " : " << cnt << "\n";
		}
	}
	if(x > 1) {
		if(mi[x] >= 1) {
			smi[x] = mi[x];
			mi[x] = 1;
		} else if(smi[x] > 1) {
			smi[x] = 1;
		}
		//~ cout << x << " : " << 1 << "\n";
	}
	//~ cout <<"---------\n";
}

ll fast_pow(ll a,int b) {
	ll w = 1;
	while(b > 0) {
		if(b&1) w*=a;
		a*=a;
		b/=2;
	}
	return w;
}

int main() {_
	cin >> n;
	for(int i = 1; i <= 200*1000; ++i) mi[i] = smi[i] = INF;
	for(int a,i = 1; i <= n; ++i) {
		cin >> a;
		ile[a]++;
		factor(a);
	}
	ll ans = 1;
	for(int i = 2; i <= 200*1000; ++i) {
		if(!pr[i]) {
			int licz = 0;
			for(ll j = (ll)i; j <= 200*1000; j+=i) {
				pr[j] = 1;
				licz += ile[j];
			}
			//if(i == 5) cout<< fast_pow(5,mi[i]) << " " << licz << "\n";
			if(licz == n-1) {
				ans *= fast_pow(i,mi[i]);
			} else if(licz == n) {
				ans *= (fast_pow(i,smi[i]));
			}
		}
	}
	cout << ans;
}