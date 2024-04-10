#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 500005
int N, A, B, T;
char ar[MAXN];
int aux[MAXN];
int aux2[MAXN];

int get(int n) {
	return ar[(n + 2 * N) % N] == 'w' ? B : 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> A >> B >> T;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		ar[i] = s[i];
	}

	int t = 0;
	for (int i = 0; i < N; i++) {
		int g = get(i) + 1 + A;
		t += g;
		aux[i] = t;
	}

	t = 0;
	for (int i = N - 1; i >= 0; i--) {
		int g = get(i) + 1 + A;
		t += g;
		aux2[i] = -t;
	}

	// turnaround spot
	int ans = 0;
	for (int ts = 0; ts < N; ts++) {
		int curra = 0;
		int t = -A;
		bool fail = false;
		t += aux[ts];
		curra += ts;
		if (t > T) {
			ans = max(curra, ans);
			break;
		}
		curra++;
		if (ts == N - 1) {
			ans = N;
			break;
		}
		t += A * ts;
		if (t > T) {
			continue;
		}

		auto it = lower_bound(aux2, aux2 + N, -(T - t));
		int amt = aux2 + N - it;
		curra += amt;
		curra = min(curra, N);
		ans = max(curra, ans);
	}

	// start on going left
	for (int ts = N; ts >= 1; ts--) {
		int curra = 0;
		int t = -A;
		bool fail = false;
		t += -aux2[ts] + A + 1 + get(0);
		curra += N - ts;
		if (t > T) {
			ans = max(curra, ans);
			break;
		}
		curra++;
		if (ts == 1) {
			ans = N;
			break;
		}
		t += A * (N - ts);
		if (t > T) {
			continue;
		}

		auto it = upper_bound(aux, aux + N, T - t + aux[0]);
		it--;
		int amt = it - aux;
		curra += amt;
		curra = min(curra, N);
		ans = max(curra, ans);
	}

	cout << min(ans, N) << endl;
	return 0;
}