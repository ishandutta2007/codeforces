// author: erray
#undef DEBUG 
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M + 1));
  vector<vector<int>> ra;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= M; ++j) {
      cin >> A[i][j];
    }
    if ((set<int>(A[i].begin(), A[i].begin() + M).size()) == M) {
      ra.push_back(A[i]);
    }
  }
  swap(A, ra);
  N = int(A.size());
  sort(A.begin(), A.end(), [&](auto x, auto y) {
    return x[M] < y[M];
  });
  if (N == 0) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> all;
  for (auto e : A) {
    for (int j = 0; j < M; ++j) {
      all.push_back(e[j]);
    }
  }
	
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (auto& e : A) {
	  for (int j = 0; j < M; ++j) {
	    e[j] = int(lower_bound(all.begin(), all.end(), e[j]) - all.begin());
	  }
	}

	debug(A);
	int size = int(all.size());
	vector<long long> h(size);
	for (int i = 0; i < size; ++i) {
	  h[i] = uniform_int_distribution<long long>(1, 1LL << 60)(rng);
	}

	debug(h);
	vector<vector<long long>> hs(N, vector<long long>(1 << M));
	vector<long long> ah;
	for (int i = 0; i < N; ++i) {
	  for (int j = 1; j < (1 << M); ++j) {
	    for (int t = 0; t < M; ++t) {
	      if (j & (1 << t)) {
	        hs[i][j] ^= h[A[i][t]];
	      }
	    } 
	    ah.push_back(hs[i][j]);
	  }
	}

	debug(hs);
	sort(ah.begin(), ah.end());
	ah.erase(unique(ah.begin(), ah.end()), ah.end());
	for (int i = 0; i < N; ++i) {
	  for (int j = 1; j < (1 << M); ++j) {
	    hs[i][j] = int(lower_bound(ah.begin(), ah.end(), hs[i][j]) - ah.begin());
	  }
	}

	debug(hs);

	int hsize = int(ah.size());
	vector<vector<int>> inds(hsize);
	for (int i = 0; i < N; ++i) {
	  for (int j = 1; j < (1 << M); ++j) {
	    inds[hs[i][j]].push_back(i);
	  }
	}
	debug(inds);

	auto Lower = [&](int l, int x) {
	  return int(lower_bound(inds[x].begin(), inds[x].end(), l + 1) - inds[x].begin());
	};


	auto Get = [&](int x, int l) {
	  int tot = 0;
	  vector<int> res(1 << M);
	  vector<int> dec(1 << M);
	  for (int b = ((1 << M) - 1); b > 0; --b) {
	    res[b] += Lower(l, hs[x][b]);
	    for (int j = (b - 1) & b; j > 0; j = (j - 1) & b) {
	      res[j] -= res[b];
	    }
	    tot += res[b];
	    dec[b] += res[b];
	  }
	  debug(x, l, tot);
	  return tot < (l + 1);
	};
	debug(A);

	bool found = false;
	int p = N;
	int ans = int(2e9);
	for (int i = 0; i < N; ++i) {
	  if (!found) {
	    p = i;
	  }
	  if (p < 0 || !Get(i, p)) {
	    continue;
	  }
	  found = true;
	  debug(i);
	  while (p > 0 && Get(i, p - 1)) {
	    --p;
	  }
	  debug(i, p);
	  ans = min(ans, A[i][M] + A[p][M]);
	  --p;
	}

	cout << (found ? ans : -1LL) << '\n';
}