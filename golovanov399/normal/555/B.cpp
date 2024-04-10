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

inline long long nxtll(){
	long long x;
	scanf("%I64d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt();
	vector<pair<long long, long long>> a(n);
	for (int i = 0; i < n; i++){
		a[i].x = nxtll();
		a[i].y = nxtll();
	}
	vector<pair<long long, int>> mm(m);
	for (int i = 0; i < m; i++)
		mm[i] = {nxtll(), i + 1};
	sort(all(mm));
	vector<pair<pair<long long, long long>, int>> b(n - 1);
	for (int i = 0; i < n - 1; i++){
		b[i].x = {a[i + 1].x - a[i].y, a[i + 1].y - a[i].x};
		b[i].y = i;
	}
	sort(all(b));

	set<pair<long long, int>> S;
	long long cur = 0;
	vector<int> ans(n - 1);
	
	int cnt = 0;
	int j = 0;
	for (int i = 0; i < m; i++){
		while (j < n - 1 && b[j].first.first <= mm[i].first){
			S.insert({b[j].first.second, b[j].second});
			j++;
		}
		if (!S.empty() && mm[i].first > S.begin()->first){
			puts("No");
			return 0;
		}
		if (!S.empty()){
			ans[S.begin()->second] = mm[i].second;
			S.erase(S.begin());
			cnt++;
		}
	}

	if (cnt < n - 1){
		puts("No");
	} else {
		puts("Yes");
		for (auto x : ans)
			printf("%d ", x);
		puts("");
	}

	return 0;
}