#include<bits/stdc++.h>

struct seg {
	int l, r;
	bool t;
};

inline bool cmp(const seg &p,const seg &q){ return p.l < q.l;}

int main() {
	using namespace std;

	int N; cin >> N;

	vector<seg> S(N);
	for(int i=0; i<(int)S.size(); ++i) { seg &s = S[i];
		cin >> s.l >> s.r;
		int t; cin >> t;
		s.t = t-1;
	}
	vector<int> coords(N);
	for (int i = 0; i < N; i++) {
		coords[i] = S[i].l;
	}
	sort(coords.begin(), coords.end());
	coords.resize(unique(coords.begin(), coords.end()) - coords.begin());

	for(int i=0; i<(int)S.size(); ++i) { seg &s = S[i];
		s.l = int(lower_bound(coords.begin(), coords.end(), s.l) - coords.begin());
		s.r = int(upper_bound(coords.begin(), coords.end(), s.r) - coords.begin());
	}
	
	sort(S.begin(), S.end(), cmp);
	
	priority_queue<int, vector<int>, greater<int> > vals[2];
	int pref_val[2] = {0, 0};
	for(int i=0; i<(int)S.size(); ++i) { seg &s = S[i];
		for (int z = 0; z < 2; z++) {
			while (!vals[z].empty() && vals[z].top() <= s.l) {
				pref_val[z]++; vals[z].pop();
			}
		}
		for (int z = 0; z < 2; z++) {
			while (pref_val[z] < pref_val[!z]) {
				pref_val[z]++;
				if (!vals[z].empty()) vals[z].pop();
			}
		}
		vals[s.t].push(s.r);
	}
	printf("%d",pref_val[0] + max((int)vals[0].size(), (int)vals[1].size()));

	return 0;
}