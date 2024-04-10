#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 1000100;

vector <int> prosti;
int djelitelj[maxn];

void euler_sieve()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!djelitelj[i]) prosti.push_back(i);
		for(int j = 0; i * prosti[j] < maxn; j++)
		{
			djelitelj[i * prosti[j]] = prosti[j];
			if(i % prosti[j] == 0) break;
		}
	}
	return;
}

bool fakt[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	euler_sieve();
	int t;
	cin >> t;
	REP(tt, t) {
		int n, rj = 0, poc_rj = 0, a, q, b;
		ll w;
		cin >> n;
		map <int, int> kolko;
		vector <int> svi(n);
		REP(i, n) {
			vector <int> tr_dj;
			cin >> a;
			b = a;
			while(a != 1) {
				if(djelitelj[a] == 0) {
					tr_dj.push_back(a);
					if(fakt[a]) {
						b /= a * a;
						fakt[a] = 0;
					}
					else fakt[a] = 1;
					a /= a;
					break;
				}
				else {
					tr_dj.push_back(djelitelj[a]);
					if(fakt[djelitelj[a]]) {
						b /= djelitelj[a] * djelitelj[a];
						fakt[djelitelj[a]] = 0;
					}
					else fakt[djelitelj[a]] = 1;
					a /= djelitelj[a];
				}
			}
			for(int d : tr_dj) fakt[d] = 0;
			kolko[b]++;
			svi.push_back(b);
			poc_rj = max(poc_rj, kolko[b]);
		}
		rj = poc_rj;
		for(int neki : svi) {
			if(neki == 1) continue;
			if(kolko[neki] % 2 == 0) {
				kolko[1] += kolko[neki];
				rj = max(rj, kolko[1]);
				kolko[neki] = 1;
			}
		}
		cin >> q;
		REP(qq, q) {
			cin >> w;
			if(w == 0) cout << poc_rj << "\n";
			else cout << rj << "\n";
		}
	}
	return 0;
}