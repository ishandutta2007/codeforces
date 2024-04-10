#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[200055];

int N;

void solve() {
	cin >> N;
	for(int i = N; i--;) cin >> A[i];
	sort(A, A+N);

	for(int i = 0; i < N/2; i++)
		cout << A[i+1] << ' ' << A[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	while(T--) solve();
	return 0;
}