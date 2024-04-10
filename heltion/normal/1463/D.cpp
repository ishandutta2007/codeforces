#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n, ans = 0;
		cin >> n;
		vector<int> v(2 * n + 1);
		for(int i = 0, b; i < n; i += 1){
			cin >> b;
			v[b] = 1;
		}
		vector<int> a, b;
		for(int i = 1; i <= 2 * n; i += 1) (v[i] ? a : b).push_back(i);
		int L = 0, R = n;
		while(L < R){
			int M = (L + R + 1) / 2, ok = 1;
			for(int i = 0; i < M; i += 1) if(a[i] > b[n - M + i]) ok = 0;
			if(ok) L = M;
			else R = M - 1;
		}
		int X = 0, Y = n; 
		while(X < Y){
			int M = (X + Y + 1) / 2, ok = 1;
			for(int i = 0; i < M; i += 1) if(b[i] > a[n - M + i]) ok = 0;
			if(ok) X = M;
			else Y = M - 1;
		}
		cout << L - (n - X) + 1 << '\n';
	}
	return 0;
}
//1 4 5 9 10
//2 3 6 7 8