#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define A first
#define B second

const int MAXN = 2e5;
const int MAXM = 2e5;

ll N, M;
ll A[MAXN];
pair<pii, ll> Q[MAXM];

ll ans[MAXM];

vector<pair<pii, pii>> lines; // segments, first pair is range, second pair is pair of slope, intercept

inline ll eval(pii l, ll x) {
	return x * l.A + l.B;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(ll i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for(ll i = 0; i < M; i++) {
		cin >> Q[i].A.B >> Q[i].A.A;
		Q[i].B = i;
	}
	sort(Q, Q + M);

	ll pref = 0;

	ll q = 0;
	for(ll j = 1; j <= N; j++) {
		pref += A[j];
		pii cur(A[j], pref - j * A[j]);
		pii range(0, j);
		while(!lines.empty()) {
			auto &l = lines.back();
			if(eval(cur, l.A.A) >= eval(l.B, l.A.A)) {
				lines.pop_back();
				continue;
			} else {
				ll mi = l.A.A;
				ll ma = l.A.B + 1;
				while(ma - mi > 1) {
					ll md = (mi + ma) / 2;
					if(eval(cur, md) >= eval(l.B, md)) {
						ma = md;
					} else {
						mi = md;
					}
				}
				l.A.B = mi;
				range.A = ma;
				break;
			}
		}
		lines.push_back(make_pair(range, cur));
		for(auto l : lines) {
			//.cerr << l.A.A << '-' << l.A.B << ' ' << l.B.A << "x + " << l.B.B << '\n';
		}
		//cerr << '\n';
		while(q < M && Q[q].A.A == j) {
			ll i = j - Q[q].A.B;
			auto l = upper_bound(lines.begin(), lines.end(), make_pair(pii(i, j + 1), pii(0, 0)));
			assert(l != lines.begin());
			l --;
			ans[Q[q].B] = pref - eval(l->B, i);

			q++;
		}
	}

	for(ll i = 0; i < M; i++) {
		cout << ans[i] << '\n';
	}
}