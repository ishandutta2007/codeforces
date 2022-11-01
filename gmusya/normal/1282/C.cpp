#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

struct problem {
	ll complexity, time;
};

bool cmp(problem a, problem b) {
	return a.time < b.time;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, t, a, b;
		cin >> n >> t >> a >> b;
		vector <problem> problems(n);
		vector <ll> firstsolved(n);
		vector <ll> secondsolved(n);
		for (ll i = 0; i < n; i++)
			cin >> problems[i].complexity;
		for (ll i = 0; i < n; i++)
			cin >> problems[i].time;
		sort(problems.begin(), problems.end(), cmp);
		if (problems[0].complexity == 0) {
			firstsolved[0] = 1;
			secondsolved[0] = 0;
		}
		else {
			firstsolved[0] = 0;
			secondsolved[0] = 1;
		}
		for (ll i = 1; i < n; i++) {
			if (problems[i].complexity == 0) {
				firstsolved[i] = firstsolved[i - 1] + 1;
				secondsolved[i] = secondsolved[i - 1];
			}
			else {
				firstsolved[i] = firstsolved[i - 1];
				secondsolved[i] = secondsolved[i - 1] + 1;
			}
		}
		vector <ll> answer(n);
		problems.push_back({ 0, t + 1 });
		for (ll i = 0; i < n; i++) {
			ll cur_time = problems[i + 1].time - 1;
			ll cur_problems = 0;
			if (firstsolved[i] * a + secondsolved[i] * b < problems[i + 1].time) {
				cur_problems += firstsolved[i] + secondsolved[i];
				cur_time -= firstsolved[i] * a + secondsolved[i] * b;
				if (cur_time >= (firstsolved[n - 1] - firstsolved[i]) * a) {
					cur_problems += firstsolved[n - 1] - firstsolved[i];
					cur_time -= (firstsolved[n - 1] - firstsolved[i]) * a;
					cur_problems += min(secondsolved[n - 1] - secondsolved[i], cur_time / b);
				}
				else {
					cur_problems += min(firstsolved[n - 1] - firstsolved[i], cur_time / a);
				}
			}
			answer[i] = cur_problems;
		}
		ll cur_time = problems[0].time - 1;
		ll cur_problems = 0;
		if (cur_time >= firstsolved[n - 1] * a) {
			cur_problems += firstsolved[n - 1];
			cur_time -= firstsolved[n - 1] * a;
			cur_problems += min(secondsolved[n - 1], cur_time / b);
		}
		else {
			cur_problems += min(firstsolved[n - 1], cur_time / a);
		}
		answer.push_back(cur_problems);
		ll ma = answer[0];
		for (auto now : answer)
			ma = max(now, ma);
		cout << ma << endl;
	}
	return 0;
}

/*
1
3 5 1 3
0 0 1
2 1 4
*/