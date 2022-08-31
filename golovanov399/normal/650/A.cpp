#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++){
		a[i].x = nxt();
		a[i].y = nxt();
	}
	sort(all(a));

	long long ans = 0;
	int cur = 0;
	for (int i = 0; i < n; i++){
		if (i == 0 || a[i].x != a[i - 1].x)
			cur = 0;
		else
			cur += 1;
		ans += cur;
	}

	sort(all(a), [](const pair<int, int>& p, const pair<int, int>& q){
		return p.y < q.y || (p.y == q.y && p.x < q.x);
	});
	for (int i = 0; i < n; i++){
		if (i == 0 || a[i].y != a[i - 1].y)
			cur = 0;
		else
			cur += 1;
		ans += cur;
	}
	for (int i = 0; i < n; i++){
		if (i == 0 || a[i] != a[i - 1])
			cur = 0;
		else
			cur += 1;
		ans -= cur;
	}

	cout << ans << "\n";

	return 0;
}