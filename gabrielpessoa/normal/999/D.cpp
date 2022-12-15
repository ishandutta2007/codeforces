#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const int ms = 2e5+5, me = 5005, sigma = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
typedef vector<int> vi;

int a[ms];
stack<int> qnt[ms];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		qnt[a[i]%m].push(i);
	}
	queue<ii> q;
	queue<ii> fim;
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		while(qnt[i].size() > n/m) {
			q.push({i, qnt[i].top()});
			qnt[i].pop();
		}
		while(qnt[i].size() < n/m) {
			if(!q.empty()) {
				ans += i - q.front().first;
				a[q.front().second] += i - q.front().first;
				q.pop();
				qnt[i].push(0);
			} else {
				fim.push({i, 0});
				qnt[i].push(0);
			}
		}
	}
	assert(fim.size() == q.size());
	while(!fim.empty() && !q.empty()) {
		ans += m - q.front().first + fim.front().first;
		a[q.front().second] += m - q.front().first + fim.front().first;
		q.pop();
		fim.pop();
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}