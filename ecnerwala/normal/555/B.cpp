#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N;
int M;
ll L[300000];
ll R[300000];
int res[300000];

pll st[300000];

pll B[300000];

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}
	for(int i = 0; i < M; i++) {
		cin >> B[i].first;
		B[i].second = i + 1;
	}
	sort(B, B + M);
	N--;
	for(int i = 0; i < N; i++) {
		L[i] = R[i + 1] - L[i];
		R[i] = L[i + 1] - R[i];
		swap(L[i], R[i]);
	}
	for(int i = 0; i < N; i++) {
		st[i] = pll(L[i], i);
	}
	sort(st, st + N);

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for(int i = 0, j = 0; i < M; i++) {
		ll v = B[i].first;
		while(j < N && st[j].first <= v) {
			int k = st[j].second;
			pq.push(pll(R[k], k));
			j++;
		}
		if(pq.empty()) continue;
		if(pq.top().first < v) {
			cout << "No\n";
			return 0;
		}
		res[pq.top().second] = B[i].second;
		pq.pop();
	}
for(int i = 0; i < N; i++) if(!res[i]) {
cout << "No\n";
return 0;
}

	cout << "Yes\n";
	for(int i = 0; i < N; i++) cout << res[i] << ' '; cout << '\n';

	return 0;
}