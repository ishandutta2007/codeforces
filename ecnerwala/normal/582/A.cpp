#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T> T gcd(T a, T b) { return a ? gcd( b % a, a ) : b; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

const int MAXN = 1e3;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	priority_queue<int> vals;
	priority_queue<int> found;
	for(int i = 0; i < N * N; i++) {
		int v; cin >> v;
		vals.push(v);
	}
	for(int i = 0; i < N; i++) {
		while(!vals.empty() && !found.empty() && vals.top() == found.top()) {
			vals.pop();
			found.pop();
		}
		A[i] = vals.top();
		vals.pop();
		for(int j = 0; j < i; j++) {
			int g = gcd(A[i], A[j]);
			found.push(g);
			found.push(g);
		}
	}
	assert(found.size() == vals.size());
	for(int i = 0; i < N; i++) cout << A[i] << ' '; cout << '\n';
	return 0;
}