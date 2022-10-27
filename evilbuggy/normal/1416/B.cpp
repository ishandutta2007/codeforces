#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int a[N];
vector<array<int, 3> > ops;

void move(int i, int j, int x){
	ops.push_back({i, j, x/i});
	a[i] -= x;
	a[j] += x;
}

void solve(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	ops.clear();
	if(sum%n != 0){
		cout << -1 << '\n';
		return;
	}
	for(int i = 2; i <= n; i++){
		int req = 0;
		if(a[i]%i != 0)req = i - (a[i]%i);
		assert(a[1] >= req);
		move(1, i, req);
		move(i, 1, a[i]);
	}
	for(int i = 2; i <= n; i++){
		move(1, i, sum/n);
	}
	cout << (int)ops.size() << '\n';
	for(auto x : ops){
		cout << x[0] << " " << x[1] << " " << x[2] << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}