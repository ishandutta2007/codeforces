#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int K = 9;
const int MAXN = 100500;

int a[2][2], cnt[2];
string s;

int main() {

	forn(i, 2)
		forn(j, 2)
			cin >> a[i][j];
			
	for (int i = 0; i < 2; i++) {
		cnt[i] = 1;
		while (1ll * cnt[i] * (cnt[i] - 1) / 2 < a[i][i])
			cnt[i]++;

		if (1ll * cnt[i] * (cnt[i] - 1) / 2 > a[i][i]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	
	s = "";
	
	//cnt[0/1] = 0?
	forn(i, 2) {
		bool zero = 1;
		forn(j, 2)
			forn(k, 2)
				if ((j != i || k != i) && a[j][k] != 0)
					zero = 0;
					
		if (zero) {
			forn(j, cnt[i])
				s += char('0' + i);
			cout << s << '\n';
			return 0;
		}
	}
	
	if (1ll * cnt[0] * cnt[1] != (a[0][1] + a[1][0])) {
		cout << "Impossible\n";
		return 0;
	}

	//set a[1][0] to 0
	int rest = a[1][0];
	while (rest >= cnt[0]) {
		s += '1';
		cnt[1]--;
		rest -= cnt[0];	
	}
	
	forn(i, cnt[0])
		s += '0';
		
	if (rest == 0) {
		forn(j, cnt[1])
			s += '1';	
	} else {
		s += '1';
		cnt[1]--;
		
		int ptr = (int)s.size() - 1;
		forn(i, rest) {
			swap(s[ptr], s[ptr - 1]);
			ptr--;
		}
		
		forn(j, cnt[1])
			s += '1';
	}
	
	cout << s << '\n';
	
	/*		
	forn(i, s.size())
		forab(j, i + 1, s.size())
			a[s[i] - '0'][s[j] - '0']--;
	forn(i, 2)
		forn(j, 2)
			assert(a[i][j] == 0);
	*/
	return 0;
}