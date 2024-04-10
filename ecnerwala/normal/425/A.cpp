#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 400;
const int MAXK = 20;

int N, K;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> A[i];

	int res = A[0];
	for(int l = 0; l < N; l++) {
		for(int r = l; r < N; r++) {
			int sz = r - l + 1;
			int s = min(K, min(sz, N - sz)); // num to swap
			priority_queue<int> out;
			priority_queue<int> in;
			for(int i = 0; i < l; i++) out.push(A[i]);
			for(int i = r + 1; i < N; i++) out.push(A[i]);
			for(int i = l; i <= r; i++) in.push(-A[i]);
			for(int i = 0; i < K && !out.empty() && !in.empty() && out.top() > -in.top(); i++) {
				int a = -in.top(); in.pop();
				int b = out.top(); out.pop();
				out.push(a);
				in.push(-b);
			}
			int val = 0;
			while(!in.empty()) {
				val -= in.top(); in.pop();
			}
			//cerr << l << ' ' << r << ' ' << sz << ' ' << s << ' ' << val << '\n';
			if(val > res) res = val;
		}
	}
	cout << res << '\n';
	return 0;
}