#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int inf = 1e9;
const int maxn = 1e6 + 100;

bool cmp(pair <int, int> A, pair <int, int> B) {
	if(A.first != B.first) return A.first < B.first;
	return A.first > B.first;
}

vector <pair <int, pair <int, int> > > pob;
int dos[maxn];
multiset <int> maxi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > svi(n), rob, svj;
	int a, b;
	REP(i, n) {
		cin >> a >> b;
		svi[i] = make_pair(a, b);
	}
	sort(svi.begin(), svi.end());
	int zad = inf, ptr = 0;
	while(ptr < n) {
		if(svi[ptr].second < zad) {
			zad = svi[ptr].second;
			rob.push_back(svi[ptr]);
			int tr = svi[ptr].first;
			while(ptr < n && svi[ptr].first == tr) ptr++;
		}
		else ptr++;
	}
	n = rob.size();
	svi.clear();
	svi.resize(m);
	REP(i, m) {
		cin >> a >> b;
		svi[i] = make_pair(a, b);
	}
	sort(svi.begin(), svi.end(), cmp);
	zad = inf, ptr = 0;
	while(ptr < m) {
		if(svi[ptr].second < zad) {
			zad = svi[ptr].second;
			svj.push_back(svi[ptr]);
			int tr = svi[ptr].first;
			while(ptr < m && svi[ptr].first == tr) ptr++;
		}
		else ptr++;
	}
	m = svj.size();
	ptr = 0;
	REP(i, n) {
		while(ptr < m && svj[ptr].first < rob[i].first) ptr++;
		if(ptr < m) {
			dos[i] = max(0, svj[ptr].second - rob[i].second + 1);
			maxi.insert(-max(0, svj[ptr].second - rob[i].second + 1));
		}
		else {
			dos[i] = 0;
			maxi.insert(0);
		}
		for(int j = ptr; j < m; j++) {
			if(j == m - 1) {
				pob.push_back(make_pair(svj[j].first - rob[i].first + 1, make_pair(i, 0)));
			}
			else {
				pob.push_back(make_pair(svj[j].first - rob[i].first + 1, make_pair(i, max(0, svj[j + 1].second - rob[i].second + 1))));
			}
		}
	}
	sort(pob.begin(), pob.end());
	ptr = 0;
	int rj = inf;
	REP(i, maxn) {
		while(ptr < (int)pob.size() && pob[ptr].first == i) {
			int tko = pob[ptr].second.first;
			int nova = pob[ptr].second.second;
			maxi.erase(maxi.find(-dos[tko]));
			dos[tko] = nova;
			maxi.insert(-dos[tko]);
			ptr++;
		}
		rj = min(rj, (-*maxi.begin()) + i);
		//cout << i << " " << rj << endl;
	}
	cout << rj << "\n";
	return 0;
}