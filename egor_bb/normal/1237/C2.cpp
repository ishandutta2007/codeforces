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

int x[N], y[N], z[N], coordX[N], cntX;
set<int> gotY[N];
map<int, set<pii>> gotZ[N];
int ind[N], removed[N];

int getCoord(int t) {
	return lower_bound(coordX, coordX + cntX, t) - coordX;
}

bool cmp(int i, int j) {
	return mp(mp(x[i], y[i]), z[i]) < mp(mp(x[j], y[j]), z[j]);
}

void clean(int i) {
	removed[i] = 1;
	gotZ[x[i]][y[i]].erase(mp(z[i], i));
	if (gotZ[x[i]][y[i]].empty()) {
		gotY[x[i]].erase(y[i]);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    forn(i, n) {
    	cin >> x[i] >> y[i] >> z[i];
    	coordX[i] = x[i];
    }
    sort(coordX, coordX + n);
    cntX = unique(coordX, coordX + n) - coordX;
    forn(i, n) {
		x[i] = getCoord(x[i]);
    	gotY[x[i]].insert(y[i]);
    	gotZ[x[i]][y[i]].insert(mp(z[i], i));
    }
    forn(i, n) {
    	ind[i] = i;
    }
    sort(ind, ind + n, &cmp);
    forn(i, n) {
    	int cur = ind[i];
    	if (removed[cur]) continue;
    	auto& mySet = gotZ[x[cur]][y[cur]];
    	clean(cur);
    	if (!mySet.empty()) {
    		int other = mySet.begin()->snd;
    		cout << cur + 1 << " " << other + 1 << '\n';
    		clean(other);
    	} else if (!gotY[x[cur]].empty()) {
    		int yVal = *gotY[x[cur]].begin();
    		auto& nextSet = gotZ[x[cur]][yVal];
    		auto it = nextSet.lower_bound(mp(z[cur], -1));
    		if (it == nextSet.end()) it--;
    		int other = it->snd;
    		cout << cur + 1 << " " << other + 1 << '\n';
    		clean(other);
    	} else {
    		int xVal = x[cur] + 1;
    		while(gotY[xVal].empty()) xVal++;
    		auto it = gotY[xVal].lower_bound(y[cur]);
    		if (it == gotY[xVal].end()) it--;
    		int yVal = *it;
    		auto& nextSet = gotZ[xVal][yVal];
    		auto it2 = nextSet.lower_bound(mp(z[cur], -1));
    		if (it2 == nextSet.end()) it2--;
    		int other = it2->snd;
    		cout << cur + 1 << " " << other + 1 << '\n';
    		clean(other);
    	}
    }
    return 0;
}