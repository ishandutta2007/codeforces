#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

typedef pair<pl2, pl2> pl4;
const int N = 1048576;
ll fen[1048580], val[1000020];
set<pl4> v;

void upd(int pos, ll val){
	for (int i = pos; i < N; i += i&-i){ fen[i] += val; }
}
ll qry(int pos){
	ll res = 0;
	for (int i = pos; i > 0; i -= i&-i){ res += fen[i]; }
	return res;
}

void Main(){
	int n, q; cin >> n >> q;
	v.insert({ {1, n}, {1, 0} });
	while (q--){
		string m; cin >> m;
		if (m[0] == 'C'){
			int l, r, c; cin >> l >> r >> c;
			auto it = v.lower_bound({ {l+1, 0}, {0, 0} }); it--;
			queue<pl4> q;
			int s = 1e9, e = 0;
			while (it != v.end()){
				pl4 p = *it;
				int st = p.fr.fr, ed = p.fr.sc;
				ll col = p.sc.fr, cal = p.sc.sc;
				if (ed < l){ it++; continue; }
				if (r < st){ break; }
				if (l < st && ed < r){
					ll res = val[col] - cal;
					upd(st, res); upd(ed+1, -res);
					s = min(s, st); e = max(e, ed);
				}
				else{
					if (st <= l && r <= ed){
						if (st < l){
							q.push({ {st, l-1}, {col, cal} });
						}
						ll res = val[col] - cal;
						upd(l, res); upd(r+1, -res);
						q.push({ {l, r}, {c, val[c]} });
						if (r < ed){
							q.push({ {r+1, ed}, {col, cal} });
						}
					}
					else{
						if (l <= st && r <= ed){
							ll res = val[col] - cal;
							upd(st, res); upd(r+1, -res);
							q.push({ {st, r}, {c, val[c]} });
							if (r < ed){
								q.push({ {r+1, ed}, {col, cal} });
							}
						}
						else{
							if (st < l){
								q.push({ {st, l-1}, {col, cal} });
							}
							ll res = val[col] - cal;
							upd(l, res); upd(ed+1, -res);
							q.push({ {l, ed}, {c, val[c]} });
						}
					}
				}
				it = v.erase(it);
			}
			while (!q.empty()){
				v.insert( q.front() ); q.pop();
			}
			if (s <= e){
				v.insert({ {s, e}, {c, val[c]} });
			}
		}
		if (m[0] == 'A'){
			int c; ll x; cin >> c >> x;
			val[c] += x;
		}
		if (m[0] == 'Q'){
			int i; cin >> i;
			ll res = qry(i);
			auto it = v.lower_bound({ {i+1, 0}, {0, 0} }); it--;
			pl4 p = *it;
			ll col = p.sc.fr, cal = p.sc.sc;
			res += val[col] - cal;
			cout << res << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}