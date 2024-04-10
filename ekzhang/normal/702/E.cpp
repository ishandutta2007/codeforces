#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
#define MAXLG 35
int N;
LL K;
int F[MAXN][MAXLG];
LL S[MAXN][MAXLG];
LL M[MAXN][MAXLG];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> F[i][0];
		// F[i][0]--;
	}

	for (int i = 0; i < N; i++) {
		cin >> S[i][0];
		M[i][0] = S[i][0];
	}

	for (int lg = 1; lg < MAXLG; lg++) {
		for (int i = 0; i < N; i++) {
			F[i][lg] = F[F[i][lg-1]][lg-1];
			S[i][lg] = S[i][lg-1] + S[F[i][lg-1]][lg-1];
			M[i][lg] = min(M[i][lg-1], M[F[i][lg-1]][lg-1]);
		}
	}

	// error(S[6][1]);

	for (int i = 0; i < N; i++) {
		// error(i);
		LL s = 0;
		LL m = 1000000000;
		int cur = i;
		LL amt = K;
		for (int lg = MAXLG - 1; lg >= 0; lg--) {
			LL x = (1LL<<lg);
			if (x <= amt) {
				amt -= x;
				s += S[cur][lg];
				m = min(m, M[cur][lg]);
				cur = F[cur][lg];
				// error(S[cur][i]);
			}
		}
		cout << s << ' ' << m << '\n';
	}

	cout.flush();
	return 0;
}