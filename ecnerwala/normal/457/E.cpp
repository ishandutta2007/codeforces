#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e12;

const int MAXN = 2.5e5;
const int MAXM = 2.5e5;

int N, M;

int par[MAXN];
ll V[MAXN]; //voltage - voltage(par)
int sz[MAXN]; // sz of the cc
vector<int> comp[MAXN]; // component
ll cmin[MAXN];
ll cmax[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		par[i] = i;
		sz[i] = 1;
		comp[i].push_back(i);
		cmin[i] = cmax[i] = V[i] = 0;
	}

	cmin[0] = INF;
	cmax[N - 1] = -INF;
	ll range = 0;
	for(int i = 0; i < M; i++) {
		int f, t, w, b;
		cin >> f >> t >> w >> b;
		f--, t--;
		ll v = w * b; // voltage difference
		v += V[f];
		f = par[f];
		v -= V[t];
		t = par[t];
		if(f == t) {
			if(v != 0) {
				cout << "BAD " << (i + 1) << '\n';
				return 0;
			} else {
				continue;
			}
		}
		// v is voltage[t] - voltage[f]
		if(sz[t] > sz[f]) {
			swap(f, t);
			v *= -1;
		}
		//append t onto f
		for(int i : comp[t]) {
			V[i] += v;
			par[i] = f;
			comp[f].push_back(i);
			sz[f] ++;
		}
		comp[t].clear(); // save memory

		cmin[f] = min(cmin[t] + v, cmin[f]);
		cmax[f] = max(cmax[t] + v, cmax[f]);

		/*
		cerr << f << ' ' << cmin[f] << ' ' <<  cmax[f] << '\n';
		for(int i = 0; i < N; i++) {
			cerr << i << ' ' << par[i] << ' ' << V[i] << '\n';
		}

		cerr << '\n';
		*/

		if(cmin[par[0]] <= V[0]) {
			cerr << "past start\n";
			cout << "BAD " << (i + 1) << '\n';
			return 0;
		}

		if(cmax[par[N - 1]] >= V[N - 1]) {
			cerr << "past end\n";
			cout << "BAD " << (i + 1) << '\n';
			return 0;
		}

		range = max(range, cmax[f] - cmin[f]);

		if(par[0] == par[N - 1] && range >= V[N - 1] - V[0]) {
			cerr << "past range\n";
			cout << "BAD " << (i + 1) << '\n';
			return 0;
		}
	}
	if(par[0] == par[N - 1]) {
		cout << V[N - 1] - V[0] << '\n';
	} else {
		cout << "UNKNOWN" << '\n';
	}
}