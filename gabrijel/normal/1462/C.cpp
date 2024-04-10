#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int inf = 1e9;

pair <int, int> rek(int target, int suma, int broj, int uzeo, int sljedeci) {
	pair <int, int> ret = make_pair(inf, inf);
	if(suma == target) return make_pair(uzeo, broj);
	else if(sljedeci == 10) return ret;
	else return min(rek(target, suma + sljedeci, broj * 10 + sljedeci, uzeo + 1, sljedeci + 1), rek(target, suma, broj, uzeo, sljedeci + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		pair <int, int> rj = rek(n, 0, 0, 0, 1);
		if(rj.first == inf) cout << -1 << "\n";
		else cout << rj.second << endl;
	}
	return 0;
}