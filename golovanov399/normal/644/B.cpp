#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), b = nxt() + 1;
	
	queue<int> q;
	queue<int> num;
	vector<long long> ans(n, -1);
	long long cur = 0;
	for (int i = 0; i < n; i++){
		int t = nxt(), d = nxt();

		while (!q.empty() && cur + q.front() <= t){
			cur += q.front();
			ans[num.front()] = cur;
			q.pop();
			num.pop();
		}

		if (q.size() < b){
			if (q.empty())
				cur = t;
			q.push(d);
			num.push(i);
		}
	}

	while (!q.empty()){
		cur += q.front();
		ans[num.front()] = cur;
		q.pop();
		num.pop();
	}

	for (auto x : ans)
		printf("%I64d ", x);
	puts("");

	return 0;
}