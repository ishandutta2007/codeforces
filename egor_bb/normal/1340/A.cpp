#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 100;

pii a[N];
int siz[N];
		
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		set<int> positions;
		multiset<int> counts;
		forn(i, n) {
			cin >> a[i].fst;
			a[i].fst--;
			a[i].snd = i;
			siz[i] = 1;
			counts.insert(1);
			positions.insert(i);
		}
		sort(a, a + n);
		bool bad = false;
		forn(i, n) {
			int pos = a[i].snd;
			if (*counts.rbegin() != siz[pos]) {
				bad = true;
				break;
			}
			positions.erase(pos);
			counts.erase(counts.find(siz[pos]));
			auto it = positions.lower_bound(pos);
			if (it == positions.end()) {
				continue;
			}
			int nextPos = *it;
			counts.erase(counts.find(siz[nextPos]));
			siz[nextPos] += siz[pos];
			counts.insert(siz[nextPos]);
		}
		if (bad) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
		
	}
	
    return 0;
}