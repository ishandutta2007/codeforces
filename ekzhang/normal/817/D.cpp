#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 1123456
int N;
int A[MAXN];
int maxl[MAXN], maxr[MAXN];
int minl[MAXN], minr[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	maxl[0] = -1;
	for (int i = 1; i < N; i++) {
		int t = i - 1;
		while (t != -1 && A[t] < A[i]) {
			t = maxl[t];
		}
		maxl[i] = t;
	}

	maxr[N - 1] = N;
	for (int i = N - 2; i >= 0; i--) {
		int t = i + 1;
		while (t != N && A[t] <= A[i]) {
			t = maxr[t];
		}
		maxr[i] = t;
	}

	minl[0] = -1;
	for (int i = 1; i < N; i++) {
		int t = i - 1;
		while (t != -1 && A[t] > A[i]) {
			t = minl[t];
		}
		minl[i] = t;
	}

	minr[N - 1] = N;
	for (int i = N - 2; i >= 0; i--) {
		int t = i + 1;
		while (t != N && A[t] >= A[i]) {
			t = minr[t];
		}
		minr[i] = t;
	}

	LL ans = 0;
	for (int i = 0; i < N; i++) {
		LL l = i - maxl[i];
		LL r = maxr[i] - i;
		ans += A[i] * l * r;

		l = i - minl[i];
		r = minr[i] - i;
		ans -= A[i] * l * r;
	}

	cout << ans << endl;
	return 0;
}