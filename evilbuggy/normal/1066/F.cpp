#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

long long dp[maxN];
array<int, 2> points[maxN];

int dist(int i, int j){
	return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> points[i][0] >> points[i][1];
	}
	points[0] = {0, 0};
	sort(points, points + n + 1, [&](array<int, 2> a, array<int, 2> b){
		if(max(a[0], a[1]) != max(b[0], b[1])){
			return max(a[0], a[1]) < max(b[0], b[1]);
		}else if(a[0] != b[0]){
			return a[0] < b[0];
		}else{
			return a[1] > b[1];
		}
	});
	dp[0] = 0;
	int pl = 0, pr = 0;
	for(int l = 1; l <= n; l++){
		int r = l;
		while(r + 1 <= n){
			if(max(points[l][0], points[l][1]) != max(points[r + 1][0], points[r + 1][1])){
				break;
			}
			r++;
		}
		dp[l] = min(dp[pl] + dist(pl, r), dp[pr] + dist(pr, r)) + dist(r, l);
		dp[r] = min(dp[pl] + dist(pl, l), dp[pr] + dist(pr, l)) + dist(l, r);
		if(r == n){
			cout << min(dp[l], dp[r]) << '\n';
		}
		pl = l; pr = r; l = r;
	}

	return 0;
}