#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > a;
	vector<pair<int, int> > b;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.emplace_back(x, i);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		b.emplace_back(x, i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> posa(n);
	vector<int> posb(n);
	for(int i = 0; i < n; i++){
		posa[a[i].second] = i;
		posb[b[i].second] = i;
	}
	int cur = n - 1, ind = posa[b[n - 1].second];
	for(int i = n - 2; i >= 0; i--){
		if(posa[b[i].second] > ind){
			for(int j = i; j < cur; j++){
				ind = min(ind, posa[b[j].second]);
			}
			cur = i;
		}
	}
	for(int i = 0; i < n; i++){
		cout << (cur <= posb[i]);
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}