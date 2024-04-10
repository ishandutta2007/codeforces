#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
typedef long long LL;
int N;
LL S;
pair<LL, LL> A[MAXN];
LL ans = 0;
LL total = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;
	LL preferb = 0;
	for (int i = 0; i < N; i++) {
		LL a, b;
		cin >> A[i].second >> a >> b;
		ans += A[i].second * a;
		A[i].first = b - a;
		if (b > a) {
			preferb += A[i].second;
		}
		total += A[i].second;
	}
	total = (total + S - 1) / S;

	sort(A, A + N);

	LL amtb = (preferb / S) * S;
	LL amt = amtb;

	LL ans1 = ans;
	for (int i = N - 1; i >= 0; i--) {
		LL diff, s;
		tie(diff, s) = A[i];
		LL k = min(s, amt);
		amt -= k;
		if (!k) break;
		ans1 += k * diff;
		assert(diff >= 0);
	}

	amt = (total - (preferb / S + 1)) * S;
	LL ans2 = ans;
	for (int i = 0; i < N; i++) {
		LL diff, s;
		tie(diff, s) = A[i];
		LL k = min(s, amt);
		amt -= k;
		if (diff > 0) k = 0;
		ans2 += (s - k) * diff;
	}

	cout << max(ans1, ans2) << endl;
	return 0;
}