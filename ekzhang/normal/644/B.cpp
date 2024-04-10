#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXN 200005
int N, B;
pair<pair<LL, LL>, int> qd[MAXN];
int q[MAXN];
int qlo = 0, qhi = 0;
LL e[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> qd[i].first.first >> qd[i].first.second;
		qd[i].second = i;
	}

	// sort(qd, qd + N);
	LL t = 0;
	for (int i = 0; i < N; i++) {
		auto x = qd[i];
		while (qlo != qhi) {
			auto curr = qd[q[qlo]];
			t = max(t, curr.first.first);
			// error(t, curr.second, curr.first.first)
			if (t + curr.first.second <= x.first.first) {
				t += curr.first.second;
				e[curr.second] = t;
				// error(curr.second, t);
				qlo++;
			}
			else break;
		}
		// error(i, qlo, qhi);
		if (qhi - qlo <= B) {
			q[qhi] = i;
			qhi++;
		}
		else {
			e[x.second] = -1;
			// error(x.second);
		}
	}

	while (qlo != qhi) {
		auto curr = qd[q[qlo]];
		t = max(t, curr.first.first);
		t += curr.first.second;
		e[curr.second] = t;
		qlo++;
	}

	for (int i = 0; i < N; i++) {
		cout << e[i] << ' ';
	}
	cout << endl;
	return 0;
}