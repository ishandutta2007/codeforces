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
	vector<pair<pair<int, int>, int>> a(n);
	for (int i = 0; i < n; i++){
		a[i].x.x = nxt();
		a[i].x.y = nxt();
		a[i].y = i;
	}
	vector<vector<int>> qw(1111);
	for (int i = 0; i < n; i++){
		qw[a[i].x.x / 1000].push_back(a[i].y);
	}
	for (int i = 0; i < 1111; i++){
		if (i % 2){
			sort(all(qw[i]), [&](int x, int y){
				return a[x].x.y < a[y].x.y;
			});
		} else {
			sort(all(qw[i]), [&](int x, int y){
				return a[x].x.y > a[y].x.y;
			});
		}
	}
	for (int i = 0; i < 1111; i++){
		for (auto x : qw[i])
			printf("%d ", x + 1);
	}
	puts("");

	return 0;
}