#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <pair <int, int> > rj;

void rek(int l, int r) {
	if(l == r) return;
	int mid = (l + r) / 2;
	rek(l, mid);
	rek(mid + 1, r);
	//cout << l << " " << r << endl;
	for(int i = l; i <= mid; i++) {
		rj.push_back(make_pair(i + 1, i + (mid - l + 1) + 1));
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, kop;
	cin >> n;
	kop = n;
	int pot = 1;
	while(kop) {
		pot *= 2;
		kop /= 2;
	}
	pot /= 2;
	rek(0, pot - 1);
	rek(n - pot, n - 1);
	cout << rj.size() << "\n";
	REP(i, (int)rj.size()) cout << rj[i].first << " " << rj[i].second << "\n";
	return 0;
}