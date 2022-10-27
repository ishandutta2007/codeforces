#include <bits/stdc++.h>
using namespace std;

const int K = 18;
const int N = 100005;

int depth[N], cnt[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	depth[1] = 0; cnt[depth[1]]++;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		depth[i] = depth[x] + 1;
		cnt[depth[i]]++;
	}
	int answer = 0;
	for(int d = 0; d <= n; d++){
		answer += (cnt[d]&1);
	}
	cout << answer << '\n';

	return 0;
}