#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 500013
int N, A[MAXN];

bool match(int amt) {
	for (int i = 0; i < amt; i++) {
		int j = N - amt + i;
		if (A[i] * 2 > A[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	int lo = 0;
	int hi = N / 2;
	while (lo != hi) {
		int mid = (lo + hi + 1) / 2;
		bool b = match(mid);
		if (b) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}

	cout << N - lo << endl;
	return 0;
}