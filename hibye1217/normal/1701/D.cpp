#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
typedef pair<pi2, int> pi3;
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

int arr[500020]; pi3 pos[500020];
int ans[500020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x; arr[i] = x;
			if (x == 0){ pos[i] = { {i+1, n}, i }; }
			else{
				int a1 = i/x, a2 = i/(x+1) + 1;
				pos[i] = { {a2, a1}, i };
			}
			//cout << "POS " << i << ' ' << x << " = " << pos[i].fr.fr << ' ' << pos[i].fr.sc << endl << flush;
		}
		sort(pos+1, pos+n+1); int ptr = 1;
		priority_stack<pi2> pq;
		for (int i = 1; i <= n; i++){
			while (ptr <= n){
				int st = pos[ptr].fr.fr, ed = pos[ptr].fr.sc;
				int idx = pos[ptr].sc;
				if (st <= i){ pq.push({ed, idx}); ptr += 1; } else{ break; }
				//cout << "PQ " << st << ' ' << ed << ' ' << idx << endl;
			}
			int idx = pq.top().sc;
			ans[idx] = i; pq.pop();
		}
		for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; } cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}