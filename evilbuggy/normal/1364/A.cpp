#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

int A[maxN];

void solve(){
	int n, x;
	cin >> n >> x;
	
	A[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		A[i] = (A[i] + A[i - 1])%x;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		if(A[i] != A[0])ans = max(ans, i);
	}
	for(int i = n; i >= 0; i--){
		if(A[n] != A[i])ans = max(ans, n - i);
	}
	if(!ans)ans = -1;
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}