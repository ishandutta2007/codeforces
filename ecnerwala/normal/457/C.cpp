#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;

const int MAXC = 2e5; //cand

int C = 1e5 + 20;

int N;
pii V[MAXN];

vector<pii> bribes[MAXC];

int cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> V[i].B >> V[i].A; // candidate number, cost
	}
	sort(V, V + N);
	for(int i = 0; i < N; i++) {
		bribes[V[i].B].push_back(pii(V[i].A, i));
	}

	list<int> candidates;
	for(int i = 0; i < C; i++) {
		if(!bribes[i].empty()) candidates.push_back(i);
	}

	int cur = 0;
	for(int i = 0; i < N; i++) {
		cur += V[i].A;
	}

	int numVotes = N;

	int pref = 0;

	int ans = cur;

	for(int v = 1; v <= N; v++) {
		if(v > 1) {
			// let them have one more
			for(__typeof(candidates.begin()) it = candidates.begin(); it != candidates.end(); ) {
				int c = *it;
				if(bribes[c].back().B < pref) {
					bribes[c].clear();
				} else {
					cur -= bribes[c].back().A;
					bribes[c].pop_back();
					numVotes --;
				}
				if(bribes[c].empty()) {
					it = candidates.erase(it);
				} else {
					it++;
				}
			}
		}
		//cerr << v << ' ' << pref << ' ' << numVotes << ' ' << cur << '\n';
		while(numVotes < v) {
			if(bribes[V[pref].B].empty() || bribes[V[pref].B].back().B < pref) {
				//cerr << pref << '\n';
				numVotes ++;
				cur += V[pref].A;
			}
			pref++;
		}
		//cerr << v << ' ' << pref << ' ' << cur << '\n';
		ans = min(ans, cur);
	}


	cout << ans << '\n';
	return 0;
}