#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e6;

int N;
char S[MAXN];

int A[MAXN]; // map from prefixes to relative order

pair<pair<int, int>, int> vals[MAXN];


//vector<int> buckets[MAXN];
//vector<int> buckets2[MAXN];

char ans[MAXN];
void build_table() {
	for(int i = 0; i < N; i++) {
		A[i] = (S[i] == ')');
	}

	for(int l = 1; l <= N; l *= 2) {
		//cerr << l << '\n';
		//for(int i = 0; i < N; i++) cerr << A[i] << ' ' << (S + i) << '\n';  cerr << '\n';

		for(int i = 0; i < N; i++) {
			vals[i] = make_pair(pair<int, int>(A[i], (i + l < N) ? A[i + l] : N), i);
		}
		/*
		for(int i = 0; i <= N; i++) {
			buckets[i].clear();
			buckets2[i].clear();
		}
		for(int i = 0; i < N; i++) {
			buckets[vals[i].second].push_back(i);
		}
		for(int i = 0; i <= N; i++) {
			for(int j : buckets[i]) {
				buckets2[vals[j].first].push_back(j);
			}
		}
		*/
		sort(vals, vals + N);
		int ind = -1;
		pair<int, int> cur(-1, -1);
		for(int i = 0; i < N; i++) {
			int v = vals[i].second;
			pair<int, int> a = vals[i].first;
			assert(a >= cur);
			if(a != cur) {
				ind++;
				cur = a;
			}
			A[v] = ind;
		}
	}
	//for(int i = 0; i < N; i++) cerr << A[i] << ' ' << (S + i) << '\n';  cerr << '\n';
}

int pref[MAXN];
int mp[MAXN];
int ms[MAXN];

int main() {
	scanf("%s", S);
	N = int(strlen(S));
	memcpy(S + N, S, N);
	N += N;
	S[N] = '|';
	S[N + 1] = 0;

	build_table();

	N /= 2;

	pref[0] = 0;
	for(int i = 0; i < N; i++) {
		pref[i + 1] = pref[i] + ((S[i] == '(') ? 1 : -1);
	}

	//for(int i = 0; i <= N; i++) cerr << pref[i] << ' '; cerr << '\n';

	mp[0] = pref[0] + pref[N];
	for(int i = 1; i < N; i++) {
		mp[i] = min(pref[i] + pref[N], mp[i - 1]);
	}
	ms[N - 1] = pref[N - 1];
	for(int i = N - 2; i >= 0; i--) {
		ms[i] = min(pref[i], ms[i + 1]);
	}

	//for(int i = 0; i <= N; i++) cerr << mp[i] << ' '; cerr << '\n';
	//for(int i = 0; i <= N; i++) cerr << ms[i] << ' '; cerr << '\n';

	int res = -1;
	for(int i = 0; i < N; i++) {
		if(min(mp[i], ms[i]) - pref[i] >= min(0, pref[N])) {
			//cerr << i << '\n';
			if(res == -1 || A[i] < A[res]) {
				res = i;
			}
		}
	}

	int ind = 0;

	for(int i = 0; i < -pref[N]; i++) {
		ans[ind++] = '(';
	}
	for(int i = 0; i < N; i++) {
		ans[ind++] = S[res + i];
	}
	for(int i = 0; i < pref[N]; i++) {
		ans[ind++] = ')';
	}
	ans[ind] = 0;
	printf("%s\n", ans);
	return 0;
}